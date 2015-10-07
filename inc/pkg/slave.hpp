#ifndef __SLAVE_H__
#define __SLAVE_H__

#include <iostream>
#include "bauer.h"

namespace fcp {
  class Slave {
  private:
    bauer::bauer_tcp_svr *_server;
    bauer::bauer_tcp_clnt _client;
  public:
    static void ExecServer(bauer::bauer_tcp_channel channel);
    Slave(short port);
  };
}
#endif
