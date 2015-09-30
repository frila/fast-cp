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
  return value_of("--file"); 
}

std::string fcp::copy_options::get_destination_ip() {
  std::string dest = value_of("--to");

  char* dest_str = new char[dest.size() + 1];
  std::copy(dest.begin(), dest.end(), dest_str);
  dest_str[dest.size()] = '\0';

  char* ip = std::strtok(dest_str, ":");
  short port = atoi(std::strtok(NULL, " "));

  std::string server_ip(ip);
  delete[] dest_str;
 
  return server_ip;
}

//TODO: Colocar porta DEFAULT
short fcp::copy_options::get_destination_port() {
  std::string dest = value_of("--to");

  char* dest_str = new char[dest.size() + 1];
  std::copy(dest.begin(), dest.end(), dest_str);
  dest_str[dest.size()] = '\0';

  char* ip = std::strtok(dest_str, ":");
  short port = atoi(std::strtok(NULL, " "));

  std::string server_ip(ip);
  delete[] dest_str;
 
  return port;
}
