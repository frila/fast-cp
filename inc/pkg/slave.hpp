#ifndef __SLAVE_H__
#define __SLAVE_H__

#include <iostream>
#include "bauer.h"

namespace fcp {
  class Slave {
  private:
  	std::string _filename;
    bauer::bauer_tcp_clnt _client_to_master;
    bauer::bauer_tcp_svr *_server;
    bauer::bauer_tcp_data_string _ip_server;
    bauer::bauer_task_serial _tasker;
  public:
    static void ExecWithoutFileServer(bauer::bauer_tcp_channel channel);
    static void ExecWithFileServer(bauer::bauer_tcp_channel channel);
    Slave(bauer::bauer_node _servernode, std::string filename);
    void connect_master(bauer::bauer_node _node_master);
    void without_file(bauer::bauer_node _nodemaster);
    void with_file(bauer::bauer_node _nodemaster);
    std::string get_filename();
  };
}
#endif
