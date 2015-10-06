#include "flag_copy.hpp"
#include "bauer.h"

void fcp::flag_copy::print_usage() {
  std::cout << "Usage: fast-cp copy [OPTIONS]" << std::endl;
  std::cout << "" << std::endl;
  std::cout << "Copies a file directly from a machine to another" << std::endl;
  std::cout << "" << std::endl;
  std::cout << "Options:" << std::endl;
  std::cout << "-f --from=./ \t\t\tThe origin directory or file that will be copied" << std::endl;
  std::cout << "-t --to= \t\t\tThe destination, specified by an valid and reachable IP address" << std::endl;
  std::cout << "-r --recursive=false \t\tSpecify if the copy is recursive or not" << std::endl;
  std::cout << "--help=false \t\t\tPrint this help" << std::endl;
}

void fcp::flag_copy::set_arguments(std::map<std::string, std::string> arguments) {
  fcp::flag::set_arguments(arguments); 
  opt.set_arguments(arguments);
}


bool fcp::flag_copy::validate_arguments() {
  if(args.empty()) {
    return false;
  }

  for(std::map<std::string, std::string>::iterator iter = args.begin(); iter != args.end(); ++iter) {
    std::string opt = iter->first;

    if(!is_valid_option(opt)) { 
      return false;
    }
  }

  if(!is_present("--to") && !is_present("-t")) {
    return false; 
  }

  return true;
}

void fcp::flag_copy::exec() {
  if(!opt.validate_options()) print_usage();

  std::string path = opt.get_path();

  std::string ip = opt.get_destination_ip();
  short port = opt.get_destination_port();

  bauer::bauer_node server(bauer::tcp_socket(), ip, port);
  bauer::bauer_tcp_clnt client;
  std::cout << "Sending " << path <<  " to " << ip << ":" << port << std::endl;

  try {
    client.connect(server);
  } catch(bauer::bauer_socket_exception) {
    std::cout << "[ERROR] Destination is not available!" << std::endl; 
    exit(1);
  }

  try {
    bauer::bauer_tcp_data_file file(path);
    file.set_send_iter_function(fcp::progress_bar::print_bar);
    client.send(file);
  } catch(bauer::bauer_exception) {
    std::cout << "[ERROR] File not found!" << std::endl; 
    exit(1);
  }
}
