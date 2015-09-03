#ifndef __ARG_PARSER__
#define __ARG_PARSER__

#include <iostream>
#include <unistd.h>
#include <getopt.h>
#include "output.hpp"
#include "flag.hpp"
#include "flag_mapper.hpp"

namespace fcp {
  class arg_parser {
  private:
    static bool validate_command(std::string command);
    static bool no_flag(int argc);
    static flag_name flag(char* argv[]);
    static flag_args flag_arguments(int argc, char* argv[]);

  public:
    static void validate(int argc, char* argv[]);
  };
}

#endif
