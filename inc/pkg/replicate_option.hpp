#ifndef __REPLICATE_OPTION__
#define __REPLICATE_OPTION__

#include <iostream>
#include <cstring>
#include "flag_arguments.hpp"
#include "bauer.h"

namespace fcp {
  class replicate_option : public flag_arguments {
  private:
  public:

    replicate_option() {
      accepted_options = {
        { "--ip", fcp::flag_option("-ip", false) },
        { "-ip", fcp::flag_option("--ip", false) },
        { "--port", fcp::flag_option("-p", false) },
        { "-p", fcp::flag_option("--port", false) },
        { "-f", fcp::flag_option("--file", false) },
        { "--file", fcp::flag_option("-f", false) },
        { "--mode", fcp::flag_option("-m", false) },
        { "-m", fcp::flag_option("--mode", false) },
        { "--master-ip", fcp::flag_option("-mi", false) },
        { "-mi", fcp::flag_option("--master-ip", false) },
        { "--master-port", fcp::flag_option("-mp", false) },
        { "-mp", fcp::flag_option("--master-port", false) }
      }; 
    };

    std::string get_filename();
    bauer_port get_port();
    bauer_ip get_ip();
    bool is_master_mode();
    bool is_provider_mode();
    bauer_ip get_master_ip();
    bauer_port get_master_port();
    
    bool validate_options();
  };
}
#endif
