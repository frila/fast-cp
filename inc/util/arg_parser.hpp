#ifndef __ARG_PARSER_
#define _ARGP_PARSER_


#include <iostream>
#include <unistd.h>
#include <getopt.h>

namespace fcp {
  class arg_parser {
  private:
    static void print_usage();
    static void print_help();

  public:
    static void validate(int argc, char* argv[]);
  };
}

#endif
