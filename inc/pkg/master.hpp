#ifndef __MASTER_H__
#define __MASTER_H__

#include <iostream>
#include <list>
#include "bauer.h"

namespace fcp {
  class Master {
  private:
    bauer::bauer_tcp_svr *master_server;
    std::list<bauer::bauer_node> ready;
    std::list<bauer::bauer_node> no_ready;

  public:
    Master(short port);
    static void ExecMasterServer(bauer::bauer_tcp_channel channel);
    std::string StateReady(bauer::bauer_node);
    std::string NoStateReady(bauer::bauer_node node);
  };
}
#endif
