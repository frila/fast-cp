#ifndef __MASTER_H__
#define __MASTER_H__

#include <iostream>
#include <list>
#include <thread>
#include "bauer.h"
#include "slave.hpp"

namespace fcp {
  class Master {
  private:
      bauer::bauer_task_serial tasker;
  public:
      std::list<std::string> ready;
      std::list<std::string> no_ready;
      bauer::bauer_tcp_svr *master_server;
      Master(bauer::bauer_node _master_node);
      void start();
      static void ExecMasterServer(bauer::bauer_tcp_channel channel);
      std::string StateReady(std::string);
      std::string NoStateReady(std::string);
  };
}
#endif
