#include "flag_mapper.hpp"

std::map<std::string, fcp::flag*> fcp::flag_mapper::flags = {
  { "copy", new fcp::flag_copy() }
};

fcp::flag* fcp::flag_mapper::flag_by_name(std::string name) {
 fcp::flag* f = flag_mapper::flags[name];
  return f;
}
