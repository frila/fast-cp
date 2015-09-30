#include "flag_recv.hpp"
#include "bauer.h"

//TODO: TESTE de arquivos enormes
void server_exec(bauer::bauer_tcp_channel channel) {
  fcp::flag_recv *flagrecv = (fcp::flag_recv *) channel.data;
  bauer::bauer_tcp_data_string filename;

  //TODO: pegar somente o nome do arquivo
  channel.recv(filename);
  bauer::bauer_tcp_data_file file(filename.get());
  channel.recv(file);
}

void fcp::flag_recv::print_usage() {
  
}

void fcp::flag_recv::set_arguments(std::map<std::string, std::string> arguments) {
  fcp::flag::set_arguments(arguments); 
  opt.set_arguments(arguments);
}

void fcp::flag_recv::exec() {
  if(!opt.validate_options()) print_usage();
  
  bauer::bauer_task_serial tasker(server_exec);

  bauer::bauer_node server_node(bauer::tcp_socket(), "127.0.0.1", opt.get_port());
  bauer::bauer_tcp_svr server(tasker, server_node);
  server.set_data(this);
  server.start();
  
}

std::string fcp::flag_recv::get_destination() {
  return opt.get_destination();
}