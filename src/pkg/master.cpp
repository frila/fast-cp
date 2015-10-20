#include <string>
#include "master.hpp"
#include "feedback.hpp"

namespace fcp {

    void Master::ExecMasterServer(bauer::bauer_tcp_channel channel) {
        feedback::log("receive slave");
        Master *master = (Master *) channel.data;
        bauer::bauer_tcp_data_string response;
        bauer::bauer_tcp_data_string _ip_recv;
        bauer::bauer_tcp_data_bool state_ready;
        channel.recv(_ip_recv);
        feedback::log("recv ip: "+_ip_recv.get());
        channel.recv(state_ready);

        if (state_ready.get()) {
            feedback::log("recv state: (with file)");
            response = master->StateReady(_ip_recv);
        } else {
            feedback::log("recv state: (without file)");
            response = master->NoStateReady(_ip_recv);
        }
        feedback::log("sending response: " + response.get() == "" ? "(no ip)" : "("+response.get()+")");
        channel.send(response);
    }

    Master::Master(bauer::bauer_node _master_node) : tasker(Master::ExecMasterServer){
        master_server = new bauer::bauer_tcp_svr(tasker, _master_node);
        master_server->set_data(this);
    }

    void Master::start(){
        feedback::log("master start server");
        feedback::log("-------------------------");
        master_server->start();
    }

    std::string Master::StateReady(std::string client) {
        feedback::log("init with file handle");
        std::string response = "";
        if(no_ready.size()) {
            feedback::log("catch ip no ready");
            std::string client_waiting = no_ready.front();
            no_ready.pop_front();
            feedback::log(std::string("ip delegate: ") + "("+client_waiting+")");
            response = client_waiting;
        } else {
            feedback::log("no have ip no ready");
            feedback::log(std::string("store slave in ready list: ")+"("+client+")");
            ready.push_back(client);
        }
        return response;
    }

    std::string Master::NoStateReady(std::string client) {
        feedback::log("init without file handle");
        std::string response = "";
        if(ready.size()) {
            feedback::log("catch ip ready");
            std::string client_ready = ready.front();
            ready.pop_front();
            feedback::log(std::string("ip delegate: ") + "("+client_ready+")");
            response = client_ready;
        } else {
            feedback::log("no have ip ready");
            feedback::log(std::string("store slave in no ready list: ")+"("+client+")");
            no_ready.push_back(client);
        }
        return response;
    }

}