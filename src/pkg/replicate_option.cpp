#include <cstdlib>
#include "replicate_option.hpp"

typedef std::map<std::string, std::string>::iterator iterator;

const std::string MODE_MASTER = "master";
const std::string MODE_SLAVE = "slave";
const std::string MODE_PROVIDER = "provider";
const std::string DEFAULT_FILENAME = "fastcp.file";
const bauer_ip DEFAULT_IP_ADDR = "127.0.0.1";
const bauer_port DEFAULT_PORT = 9400;
const bauer_port DEFAULT_MASTER_PORT = 9401;
const std::string DEFAULT_MODE = MODE_SLAVE;

bool fcp::replicate_option::validate_options() {
  for(iterator iter = args.begin(); iter != args.end(); ++iter) {
    std::string opt = iter->first;
    std::string val = iter->second;

    if(!define_values(opt, val)) {
      return false;
    }
  }
  return true;
}


bauer_port fcp::replicate_option::get_port() {
  bauer_port port = (bauer_port) std::atoi(value_of("--port").c_str());
  return port == 0 ? DEFAULT_PORT : port;
}

std::string fcp::replicate_option::get_filename(){
  std::string filename;
  if((filename = value_of("--file")) == "") {
    return DEFAULT_FILENAME;
  } else {
    return filename;
  }
}

bauer_ip fcp::replicate_option::get_ip(){
  bauer_ip ip = value_of("--ip");
  if( ip == "" ) return DEFAULT_IP_ADDR;
  else return ip;
}

bool fcp::replicate_option::is_master_mode(){
  std::string mode = value_of("--mode");
  if ( mode == "" ) mode = DEFAULT_MODE;

  if( mode == MODE_MASTER) return true;
  else return false; // TODO: throw exception
}

bool fcp::replicate_option::is_provider_mode() {
    std::string mode = value_of("--mode");
    if ( mode == "" ) mode = DEFAULT_MODE;

    if( mode == MODE_PROVIDER) return true;
    else return false; // TODO: throw exception
}

bauer_ip fcp::replicate_option::get_master_ip(){
  bauer_ip ip = value_of("--master-ip");
  if( ip == "" ) return DEFAULT_IP_ADDR;
  else return ip;
}

bauer_port fcp::replicate_option::get_master_port(){
  bauer_port port = (bauer_port) std::atoi(value_of("--master-port").c_str());
  if( port == 0 ) return DEFAULT_MASTER_PORT;
  else return port;
}
