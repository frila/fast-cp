#include "flag_arguments.hpp"

bool fcp::flag_arguments::is_valid_option(std::string option) {
  for(int i = 0; i < accepted_options.size(); i++) {
    if(accepted_options.at(i).name == option || accepted_options.at(i).alias == option) return true; 
  }

  return false;
}

