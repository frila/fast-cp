#include "flag.hpp"

//std::vector<std::string> accepted_options = {};

void fcp::flag::set_arguments(std::map<std::string, std::string> _arguments) {
  args = _arguments;
}

void fcp::flag::set_name(std::string _name) {
  name = _name;
}

bool fcp::flag::is_valid_option(std::string option) {
  if(std::find(accepted_options.begin(), accepted_options.end(), option) != accepted_options.end()) return true;
  return false;
}

std::string fcp::flag::get_value(std::string opt) {
  return args[opt];
}

bool fcp::flag::is_present(std::string opt) {
  if(args.find(opt) != args.end()) return true;
  return false;
}
