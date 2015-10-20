#include "flag_replicate.hpp"
#include "master.hpp"

void fcp::flag_replicate::print_usage() {
}

void fcp::flag_replicate::set_arguments(std::map<std::string, std::string> arguments) {
  fcp::flag::set_arguments(arguments);
  opt.set_arguments(arguments);
}

void fcp::flag_replicate::master_exec() {
  bauer::bauer_node node(bauer::tcp_socket(), opt.get_master_ip(), opt.get_master_port());
  Master master(node);
  master.start();
}

void fcp::flag_replicate::slave_exec(Slave &slave, bauer::bauer_node &_master_node) {
  slave.without_file(_master_node);
  slave_provider_exec(slave,_master_node);
}

void fcp::flag_replicate::slave_provider_exec(Slave &slave, bauer::bauer_node &_master_node){
    while(true) slave.with_file(_master_node);
}

void fcp::flag_replicate::exec() {
  if(!opt.validate_options()) print_usage();

    std::cout << "meu ip: ";
    std::cout << opt.get_ip() << ":" << opt.get_port() << std::endl;

    std::cout << "master ip: ";
    std::cout << opt.get_master_ip() << ":" << opt.get_master_port() << std::endl;

  if ( opt.is_master_mode() ) {
      master_exec();
  } else{
      bauer::bauer_node _master_node(bauer::tcp_socket(), opt.get_master_ip(), opt.get_master_port());
      bauer::bauer_node _servernode(bauer::tcp_socket(), opt.get_ip(), opt.get_port());
      std::string filename = opt.get_filename();
      Slave slave(_servernode,filename);

      if(opt.is_provider_mode()) {
          slave_provider_exec(slave,_master_node);
      } else {
          slave_exec(slave,_master_node);
      }
  }
}
