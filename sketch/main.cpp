#include <iostream>
#include <bauer.h>
#include <list>
#include <thread>
#include <mutex>
#include <condition_variable>


using namespace std;
using namespace bauer;

const bool NAO_PRONTO = false;
const bool PRONTO = true;

void serverSlaveFunction(bauer_tcp_channel remote);

/*
	Compilação:
	na pasta do bauer:
		> sudo make install
		o comando ja copia a lib e o inc pros devidos lugares
	na pasta do projeto
	g++ -std=c++11 main.cpp -o main -Wall -lbauer -pthread
*/


class Slave
{
public:
	bauer_node master_node, my_node;
	bauer_tcp_clnt clientToMaster;
	bauer_tcp_svr *server;
	bauer_tcp_data_file file;
	bauer_tcp_data_bool status;
	Slave(bauer_node _master_node, bauer_node _my_node, string path) : master_node(_master_node), my_node(_my_node), file(path)
	{
		//Conectar com o Master
		master_node.set_socket(tcp_socket());
		clientToMaster.connect(master_node);
	}

	~Slave() {}
	
	static void serverSlaveFunction(bauer_tcp_channel channel)
	{
		Slave *slave = (Slave*) channel.data;

		//Faz transferencia do arquivo
		channel.send(slave->file);

		//Enviar Pronto para Master
		slave->clientToMaster.send(slave->status);

		//Enviar o IP do Server para o Master
		{
			bauer_tcp_data_string strIpPort = bauer_node2string(slave->my_node);
			slave->clientToMaster.send(strIpPort);
		}
	
		
	}

	void runServer()
	{
		// Criar um Server Serial ( Soh vai receber uma conexao por ver )
		bauer_task_serial tasker(serverSlaveFunction);
		server = new bauer_tcp_svr(tasker, my_node);
		server->set_data(this);

		// Start no server
		server->force().start();
	}

	void exec()
	{
		bauer_tcp_data_string strIp;

		
		// Envia status de nao pronto
		status = NAO_PRONTO;
		clientToMaster.send(status);
		
		// Receber o IP
		clientToMaster.recv(strIp);
		
		// Fazer a Transferencia
		{// Feito dentro das chaves pras variaveis morrerem ao termino
			bauer_node serverToReceiveFile = string2bauer_node(strIp);
			serverToReceiveFile.set_socket(tcp_socket());
			bauer_tcp_clnt clientToAnyServer;
			clientToAnyServer.connect(serverToReceiveFile);
			clientToAnyServer.recv(file);
		}

		status = PRONTO;
	
		//Enviar Pronto para Master
		clientToMaster.send(status);

		//Enviar o IP do Server para o Master
		{
			bauer_tcp_data_string strIpPort = bauer_node2string(my_node);
			clientToMaster.send(strIpPort);
		}

		runServer();
	}
};

class Master
{
private:
public:
	bauer_node my_node_master;
	bauer_tcp_data_file file;
	list<string> free_ip;
	Slave slave;
	std::mutex mtx;
	std::condition_variable cond_var;

	Master(bauer_node _my_node_master, bauer_node _my_node_slave, string _path): 
		my_node_master(_my_node_master),
		file(_path), 
		slave(_my_node_master ,_my_node_slave, _path) {}
	
	~Master() {}

	static void serverMasterFuncion(bauer_tcp_channel channel)
	{
		Master *master = (Master*) channel.data;

		//recebe status
		bauer_tcp_data_bool status;
		channel.recv(status);

		
		//Se pronto:
		if ( status.get() )
		{
			//recebe o IP
			bauer_tcp_data_string strIp;
			channel.recv(strIp);
			// Regiao Critica, faz o lock
			{
				std::unique_lock<std::mutex> lck(master->mtx);
				//Guarda IP
				master->free_ip.push_front(strIp);
				master->cond_var.notify_one();
			}
		}
		else
		{
			bauer_tcp_data_string ip;
			//Envia IP
			{
				std::unique_lock<std::mutex> lck(master->mtx);
				while( master->free_ip.empty() )
				{
					master->cond_var.wait(lck);
				}
				ip = master->free_ip.back();
				master->free_ip.pop_back();
			}
			channel.send(ip);
		}
		
	}

	static void MasterThread(Master *master)
	{
		bauer_task_pool_thread tasker(serverMasterFuncion);
		bauer_tcp_svr server(tasker, master->my_node_master);
		server.set_data(master);
		server.force().start();
	}

	void exec()
	{
		free_ip.push_back(bauer_node2string(slave.my_node));
		new std::thread(MasterThread, this);
		slave.runServer();
	}
};

int main(int argc, char const *argv[])
{

	string path = argv[2];
	
	if (strcmp(argv[1],"master") == 0)
	{
		bauer_node my_node = string2bauer_node(argv[3]);
		string path = argv[4];
//		(new Master(my_node, path))->exec();
	}
	else
	{
		bauer_node my_node = string2bauer_node(argv[3]);
		bauer_node master_node = string2bauer_node(argv[4]);
		string path = argv[5];
		(new Slave(master_node,my_node, path))->exec();
	}
	return 0;
}