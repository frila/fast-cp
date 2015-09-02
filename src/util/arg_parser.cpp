#include "arg_parser.hpp"

const int command_position = 1;

void fcp::arg_parser::validate(int argc, char* argv[]) {
  if(argc < 2) {
    output::print_usage();
  }
}


