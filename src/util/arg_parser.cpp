#include "arg_parser.hpp"

void fcp::arg_parser::print_help() {
  fcp::output::print_usage();
}

void fcp::arg_parser::validate(int argc, char* argv[]) {
  if(argc < 2) {
    output::print_usage();
  }
}

void fcp::arg_parser::get_command(std::string command) {
      
}
