#ifndef __ARG_PARSER__
#define __ARG_PARSER__

#include <iostream>
#include <unistd.h>
#include <getopt.h>
#include "output.hpp"
#include "flag.hpp"

namespace fcp {
  class arg_parser {
  private:
    static bool validate_command(std::string command);

  public:
    static void validate(int argc, char* argv[]);
  };
}

#endif
