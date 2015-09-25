#include "copy_options.hpp"

typedef std::map<std::string, std::string>::iterator iterator;

bool fcp::copy_options::validate_options() {
  for(iterator iter = args.begin(); iter != args.end(); ++iter) {
    std::string opt = iter->first;
    std::string val = iter->second;

    if(!define_values(opt, val)) { 
      return false;
    }
  }

  return true;
}

std::string fcp::copy_options::get_path() {
    
}
