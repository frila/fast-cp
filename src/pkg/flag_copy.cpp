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

bool fcp::flag_copy::validate_arguments() {
  if(args.empty()) {
    return false;
  }

  for(std::map<std::string, std::string>::iterator iter = args.begin(); iter != args.end(); ++iter) {
    std::string opt = iter->first;

    if(!is_valid_option(opt)) { 
      return false;
    }
  }

  if(!is_present("--to") && !is_present("-t")) {
    return false; 
  }

  return true;
}

void fcp::flag_copy::exec() {
  opt.validate_options();
  if(!validate_arguments()) print_usage();
}
