#include "slave.hpp"
#include <cstdio>
#include <stdlib.h>

bauer::bauer_node stringToNode(std::string _ip){
    int b1, b2, b3, b4, port;
    b1 = b2 = b3 = b4 = port = 0;
    std::sscanf(_ip.c_str(),"%d.%d.%d.%d:%d",&b1,&b2,&b3,&b4,&port);
    std::string str = std::to_string(b1) + "." + std::to_string(b2) + "." + std::to_string(b3) + "." + std::to_string(b4);
	return bauer::bauer_node(bauer::tcp_socket(),str, port);
}

std::string nodeToString(bauer::bauer_node node) {
    return node.get_ip() + ":" + std::to_string(node.get_port());
}

void fcp::Slave::ExecWithoutFileServer(bauer::bauer_tcp_channel channel){
    Slave *slave = (Slave*)channel.data;
    std::string _filename = slave->get_filename();
	bauer::bauer_tcp_data_file _filedata(_filename);
	channel.recv(_filedata);
}

void fcp::Slave::ExecWithFileServer(bauer::bauer_tcp_channel channel){
    Slave *slave = (Slave*)channel.data;
    std::string _filename = slave->get_filename();
	bauer::bauer_tcp_data_file _filedata(_filename);
	channel.send(_filedata);
}

fcp::Slave::Slave(bauer::bauer_node _servernode, std::string filename) 
		: _filename(filename), _tasker(fcp::Slave::ExecWithoutFileServer) {
    _ip_server = nodeToString(_servernode);
	_server = new bauer::bauer_tcp_svr(_tasker, _servernode);
	_server->set_data(this);
}

void fcp::Slave::connect_master(bauer::bauer_node _node_master){
	_client_to_master.connect(_node_master);
}

void fcp::Slave::without_file(bauer::bauer_node _nodemaster) {
	
	_tasker.set_function(fcp::Slave::ExecWithoutFileServer);
	_server->unique_cicle();
	bauer::bauer_tcp_data_string _ip_dest;
	bauer::bauer_tcp_data_bool _is_ready = false;
	_nodemaster.set_socket(bauer::tcp_socket());
	_client_to_master.connect(_nodemaster);
    _client_to_master.send(_ip_server);
	_client_to_master.send(_is_ready);
	_client_to_master.recv(_ip_dest);

    if(_ip_dest.get() == "") {
		_server->start();
	} else {
		bauer::bauer_tcp_data_file _filedata(_filename);
		bauer::bauer_node node_received = stringToNode(_ip_dest);
        bauer::bauer_tcp_clnt _client;
        _client.connect(node_received);
        _client.recv(_filedata);
    }
}

void fcp::Slave::with_file(bauer::bauer_node _nodemaster){
	_tasker.set_function(fcp::Slave::ExecWithFileServer);
	_server->unique_cicle();
	bauer::bauer_tcp_data_string _ip_dest;
	bauer::bauer_tcp_data_bool _is_ready = true;

    _client_to_master.connect(_nodemaster);
    _client_to_master.send(_ip_server);
	_client_to_master.send(_is_ready);
	_client_to_master.recv(_ip_dest);

	if(_ip_dest.get() == "") {
		_server->start();
	} else {
		bauer::bauer_tcp_data_file _filedata(_filename);
		bauer::bauer_node node_received = stringToNode(_ip_dest);
		bauer::bauer_tcp_clnt _client;
		_client.connect(node_received);
		_client.send(_filedata);
	}
}

std::string fcp::Slave::get_filename() {
    return _filename;
}