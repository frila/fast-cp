#include <string>
#include "master.hpp"

#include <cstdio>

namespace fcp {

    void Master::ExecMasterServer(bauer::bauer_tcp_channel channel) {

        Master *master = (Master *) channel.data;
        bauer::bauer_tcp_data_string response;
        bauer::bauer_tcp_data_string _ip_recv;
        bauer::bauer_tcp_data_bool state_ready;

        channel.recv(_ip_recv);
        channel.recv(state_ready);

        if (state_ready.get()) {
            response = master->StateReady(_ip_recv);
        } else {
            response = master->NoStateReady(_ip_recv);
        }
        channel.send(response);
    }

    Master::Master(bauer::bauer_node _master_node) : tasker(Master::ExecMasterServer){
        master_server = new bauer::bauer_tcp_svr(tasker, _master_node);
        master_server->set_data(this);
    }

    void Master::start(){
        master_server->start();
    }

    std::string Master::StateReady(std::string client) {
        std::string response = "";
        if(no_ready.size()) {
            std::string client_waiting = no_ready.front();
            no_ready.pop_front();
            response = client_waiting;
        } else {
            ready.push_back(client);
        }
        return response;
    }

    std::string Master::NoStateReady(std::string client) {
        std::string response = "";
        if(ready.size()) {
            std::string client_ready = ready.front();
            ready.pop_front();
            response = client_ready;
        } else {
            no_ready.push_back(client);
        }
        return response;
    }

}