#ifndef __RECV_OPTIONS__
#define __RECV_OPTIONS__

#include <iostream>
#include <cstring>
#include "flag_arguments.hpp"
#include "bauer.h"

namespace fcp {
  class recv_options : public flag_arguments {
  private:
  public:
    recv_options() {
      accepted_options = {
        { "--port", fcp::flag_option("-p", true) },
        { "-p", fcp::flag_option("--port", true) },
        { "-f", fcp::flag_option("--file", false) },
        { "--file", fcp::flag_option("-f", false) }
      }; 
    };

    std::string get_destination();
    bauer_port get_port();
    
    bool validate_options();
  };
}
#endif
