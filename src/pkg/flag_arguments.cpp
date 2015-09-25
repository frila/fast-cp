#include "flag_arguments.hpp"

bool fcp::flag_arguments::define_values(std::string option, std::string value) {
  auto opt = accepted_options.find(option);

  if(opt == accepted_options.end()) {
    return false;
  }
  auto alias = accepted_options.find(opt->second.alias);
  opt->second.set_value(value);
  alias->second.set_value(value);
  return true;
}

void fcp::flag_arguments::set_arguments(std::map<std::string, std::string>_args) {
  args = _args;        
}

std::string fcp::flag_arguments::value_of(std::string key) {
  auto pos = accepted_options.find(key);
  
  return pos->second.value;
}
