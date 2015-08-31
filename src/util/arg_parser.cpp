#include "arg_parser.hpp"

const std::string fcp::arg_parser::com_copy = "copy";
const std::string fcp::arg_parser::com_replicate = "replicate";

void fcp::arg_parser::print_usage() {
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

void fcp::arg_parser::print_help() {
  fcp::arg_parser::print_usage();
}

void fcp::arg_parser::validate(int argc, char* argv[]) {
  if(argc == 0) {
    print_usage();
  }

  std::string command = std::string(argv[fcp::arg_parser::command]);
  fcp::arg_parser::get_command(command);
}

void fcp::arg_parser::get_command(std::string command) {
  print_usage(); 
}
