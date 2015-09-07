#include "flag_arguments.hpp"

bool fcp::flag_arguments::is_valid_option(std::string option) {
  for(int i = 0; i < accepted_options.size(); i++) {
    if(accepted_options.at(i).name == option || accepted_options.at(i).alias == option) return true; 
  }

  return false;
}

void fcp::flag_arguments::set_arguments(std::map<std::string, std::string>_args) {
  args = _args; 
}
