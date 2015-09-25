#include "flag_arguments.hpp"

bool fcp::flag_arguments::define_values(std::string option, std::string value) {
  auto pos = accepted_options.find(option);
  if(pos == accepted_options.end()) {
    return false;
  }
  pos->second.value = value;
  return true;
}

void fcp::flag_arguments::set_arguments(std::map<std::string, std::string>_args) {
  args = _args;        
}
