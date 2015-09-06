#include "copy_options.hpp"

bool fcp::copy_options::validate_options(std::map<std::string, std::string>args) {
  for(std::map<std::string, std::string>::iterator iter = args.begin(); iter != args.end(); ++iter) {
    std::string opt = iter->first;

    if(!is_valid_option(opt)) { 
      return false;
    }
  }

  return true;
}
