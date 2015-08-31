#include "arg_parser.hpp"

void fcp::arg_parser::print_usage() {
  std::cout << "Usage: fast-cp [COMMAND] [OPTIONS]" << std::endl;
  std::cout << "fast-cp [--help -h]" << std::endl;
  std::cout << "Simple tool to replicate files trought several machines" << std::endl;
  std::cout << "Options:" << std::endl;
  std::cout << "copy: \t\t\tCopy a file or directory to another machine" << std::endl;
  std::cout << "replicate \t\tReplicate a file or directory throught several machines" << std::endl;
  std::cout << "" << std::endl;
}

void fcp::arg_parser::validate(int argc, char* argv[]) {
  fcp::arg_parser::print_usage();
}
