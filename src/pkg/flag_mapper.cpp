#include "flag_mapper.hpp"

#include "flag_copy.hpp"
#include "flag_recv.hpp"


std::map<std::string, fcp::flag*> fcp::flag_mapper::flags = {
  { "send", new fcp::flag_copy() },
  { "recv", new fcp::flag_recv() }
};

fcp::flag* fcp::flag_mapper::flag_by_name(std::string name) {
 fcp::flag* f = flag_mapper::flags[name];
  return f;
}
