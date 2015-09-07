#ifndef __COPY_OPTIONS__
#define __COPY_OPTIONS__

#include <iostream>
#include "flag_arguments.hpp"

namespace fcp {
  class copy_options : public flag_arguments {
  private:
  public:
    copy_options() {
      accepted_options = {
        fcp::flag_option("--from", "-f", true),
        fcp::flag_option("--to", "-t", true),
        fcp::flag_option("--recursive", "-r", false),
        fcp::flag_option("--help", "-h", false)
      }; 
    };

    bool validate_options(); 
    std::string get_path();
    std::string get_destination_ip();
    std::string get_destination_port();
    bool is_recursive();
    bool print_help();
  };
}
#endif
