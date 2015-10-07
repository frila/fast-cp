#include "slave.hpp"


void fcp::Slave::ExecServer(bauer::bauer_tcp_channel channel){

}

fcp::Slave::Slave(short port) {
	bauer::bauer_task_serial tasker(Slave::ExecServer);
	bauer::bauer_node local_node(bauer::tcp_socket(), "127.0.0.1", port);
	_server = new bauer::bauer_tcp_svr(tasker, local_node);
	_server->start();
}