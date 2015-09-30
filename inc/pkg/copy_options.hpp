#ifndef __COPY_OPTIONS__
#define __COPY_OPTIONS__

#include <iostream>
#include <cstring>
#include "flag_arguments.hpp"

namespace fcp {
  class copy_options : public flag_arguments {
  private:
  public:
    copy_options() {
      accepted_options = {
        { "--file", fcp::flag_option("-f", true) },
        { "-f", fcp::flag_option("--file", true) },
        { "--to", fcp::flag_option("-t", true) },
        { "-t", fcp::flag_option("--to", true) },
        { "--recursive", fcp::flag_option("-r", false) },
        { "-r", fcp::flag_option("--recursive", false) },
      }; 
    };

    bool validate_options(); 
    std::string get_path();
    std::string get_destination_ip();
    short get_destination_port();
    bool is_recursive();
    bool print_help();
  };
}
#endif
