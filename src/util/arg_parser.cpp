#include "arg_parser.hpp"

const int flag_position = 1;
const int arguments_position = 2;

void fcp::arg_parser::validate(int argc, char* argv[]) {
  if(no_flag(argc)) {
    output::print_usage();
  }

  std::string flag_name = flag(argv);
  fcp::flag* flag = flag_mapper::flag_by_name(flag_name);
}

bool fcp::arg_parser::no_flag(int argc) {
  return (argc < 2);
}

fcp::flag_name fcp::arg_parser::flag(char* argv[]) {
  return std::string(argv[flag_position]);
}

fcp::flag_args flag_arguments(int argc, char* argv[]) {
  std::map<std::string, std::string> arguments;

  for(int i = arguments_position; i < argc; i++) {
    std::string arg(argv[i]);
    std::string next_arg(argv[i+1]);
    if(arg.at(0) == '-') { 
      if(next_arg.at(0) != '-') {
        arguments.insert(std::pair<std::string, std::string>(arg, next_arg));
      } else {
        arguments.insert(std::pair<std::string, std::string>(arg, "1"));
      }
    }
  }

  return arguments;
}
