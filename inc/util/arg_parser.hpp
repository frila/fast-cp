#ifndef __ARG_PARSER_
#define _ARGP_PARSER_


#include <iostream>
#include <unistd.h>
#include <getopt.h>
#include "output.hpp"

namespace fcp {
  class arg_parser {
  private:
    static const std::string com_copy;
    static const std::string com_replicate;
    static const int command = 1; 

    //static void print_usage();
    static void print_help();
    static void get_command(std::string command);

  public:
    static void validate(int argc, char* argv[]);
  };
}

#endif
