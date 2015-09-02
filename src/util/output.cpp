#include "output.hpp"

void fcp::output::print_usage() {
  std::cout << "Usage: fast-cp [COMMAND] [OPTIONS]" << std::endl;
  std::cout << "fast-cp [--help -h]" << std::endl;
  std::cout << "Simple tool to replicate files trought several machines" << std::endl;
  std::cout << "" << std::endl;
  std::cout << "Command:" << std::endl;
  std::cout << "copy: \t\t\tCopy a file or directory to another machine" << std::endl;
  std::cout << "replicate: \t\tReplicate a file or directory throught several machines" << std::endl;
  std::cout << "" << std::endl;
  std::cout << "Options:" << std::endl;
  std::cout << "-f --from" << std::endl;
  std::cout << "-t --to" << std::endl;
  std::cout << "-p --port" << std::endl;
  std::cout << "--save-at" << std::endl;
}

void fcp::output::print_help(std::string command) {
  print_usage();
}
