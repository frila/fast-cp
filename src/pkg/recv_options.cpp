#include <cstdlib>
#include "recv_options.hpp"

typedef std::map<std::string, std::string>::iterator iterator;

const std::string DEFAULT_NAME_DESTINATION = "fastcp.file";

bool fcp::recv_options::validate_options() {
  for(iterator iter = args.begin(); iter != args.end(); ++iter) {
    std::string opt = iter->first;
    std::string val = iter->second;

    if(!define_values(opt, val)) { 
      return false;
    }
  }
  return true;
}

std::string fcp::recv_options::get_destination() {
  std::string dest = value_of("--file");
  return dest == "" ? DEFAULT_NAME_DESTINATION : dest;
}

//TODO: Colocar porta DEFAULT
bauer_port fcp::recv_options::get_port() {
  bauer_port port = std::atoi(value_of("--port").c_str());
  return port;
}
