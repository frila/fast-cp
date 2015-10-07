#include "master.hpp"
#include <string>

namespace fcp {

	void Master::ExecMasterServer(bauer::bauer_tcp_channel channel) {
		Master *master = (Master *) channel.data;
		bauer::bauer_tcp_data_string response;
		bauer::bauer_tcp_data_bool state_ready;

		channel.recv(state_ready);

		if (state_ready.get()) {
			response = master->StateReady(channel.get_target());
		} else {
			response = master->NoStateReady(channel.get_target());
		}
		channel.send(response);
	}

	Master::Master(short port) {
		bauer::bauer_task_serial tasker(Master::ExecMasterServer);
		bauer::bauer_node local_node(bauer::tcp_socket(), "127.0.0.1", port);
		master_server = new bauer::bauer_tcp_svr(tasker, local_node);
		master_server->set_data(this);
		master_server->start();
	}

	std::string Master::StateReady(bauer::bauer_node node) {
		std::string response = "";
		if(no_ready.size()) {
			bauer::bauer_node client_waiting = no_ready.front();
			no_ready.pop_front();
			response = client_waiting.get_ip() + std::string(":") + std::string(std::to_string(client_waiting.get_port()));
		} else {
			ready.push_back(node);
		}
		return response;
	}

	std::string Master::NoStateReady(bauer::bauer_node node) {
		std::string response = "";
		if(ready.size()) {
			bauer::bauer_node client_ready = ready.front();
			ready.pop_front();
			response = client_ready.get_ip() + std::string(":") + std::string(std::to_string(client_ready.get_port()));
		} else {
			no_ready.push_back(node);
		}
		return response;
	}

}