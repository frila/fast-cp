#include "flag_copy.hpp"

std::vector<std::string> accepted_options = {
  "-f",
  "--from",
  "-t",
  "--to",
  "-r",
  "--recursive",
  "-h",
  "--help"
};

void fcp::flag_copy::print_usage() {
  std::cout << "Usage: fast-cp copy [OPTIONS]" << std::endl;
  std::cout << "" << std::endl;
  std::cout << "Copies a file directly from a machine to another" << std::endl;
  std::cout << "" << std::endl;
  std::cout << "Options:" << std::endl;
  std::cout << "-f --from=./ \t\t\tThe origin directory or file that will be copied" << std::endl;
  std::cout << "-t --to= \t\t\tThe destination, specified by an valid and reachable IP address" << std::endl;
  std::cout << "-r --recursive=false \t\tSpecify if the copy is recursive or not" << std::endl;
  std::cout << "--help=false \t\t\tPrint this help" << std::endl;
}

void fcp::flag_copy::set_arguments(std::map<std::string, std::string> _arguments) {
  args = _arguments;
}

bool fcp::flag_copy::validate_arguments() {
  if(args.empty()) {
    std::cout << "tell me what to do!" << std::endl;
    std::cout << "" << std::endl;
    return false;
  }

  for(std::map<std::string, std::string>::iterator iter = args.begin(); iter != args.end(); ++iter) {
    std::string opt = iter->first;

    if(!is_valid_option(opt)) { 
      std::cout << "don't know how to execute command " + opt << std::endl;
      std::cout << "" << std::endl;
      return false;
    }
  }

  //if(!is_present("--from") && !is_present("-f")) {
  //  args["--from"] = "./"; 
  //}

  if(!is_present("--to") && !is_present("-t")) {
    std::cout << "--to is mandatory!" << std::endl;
    std::cout << "" << std::endl;
    return false; 
  }

  return true;
}

bool fcp::flag_copy::is_valid_option(std::string option) {
  if(std::find(accepted_options.begin(), accepted_options.end(), option) != accepted_options.end()) return true;
  return false;
}

std::string fcp::flag_copy::get_value(std::string opt) {
  return args[opt];
}

bool fcp::flag_copy::is_present(std::string opt) {
  if(args.find(opt) != args.end()) return true;
  return false;
}

void fcp::flag_copy::exec() {
  if(!validate_arguments()) print_usage();
}
