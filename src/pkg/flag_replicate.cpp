#include "flag_replicate.hpp"
#include "master.hpp"
#include "feedback.hpp"

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
    feedback::log("START PROCESS WITH FILE");
    feedback::log("-----------------------------------");
  slave.without_file(_master_node);
  slave_provider_exec(slave,_master_node);
}

void fcp::flag_replicate::slave_provider_exec(Slave &slave, bauer::bauer_node &_master_node){
    feedback::log("START PROCESS WITH FILE");
    feedback::log("-----------------------------------");
    while(true) slave.with_file(_master_node);
}

void fcp::flag_replicate::exec() {
  if(!opt.validate_options()) print_usage();

  if ( opt.is_master_mode() ) {
      feedback::log(std::string("MASTER SERVER IP: ") + opt.get_master_ip()+ std::string(":")+ std::to_string(opt.get_master_port()));
      feedback::log("MASTER START");
      master_exec();
  } else{
      feedback::log(std::string("SERVER IP: ") + opt.get_ip()+ std::string(":")+ std::to_string(opt.get_port()));
      feedback::log(std::string("MASTER SERVER IP: ") + opt.get_master_ip()+ std::string(":")+ std::to_string(opt.get_master_port()));
      feedback::log("FILENAME: "+opt.get_filename());
      feedback::log("SLAVE START");
      bauer::bauer_node _master_node(bauer::tcp_socket(), opt.get_master_ip(), opt.get_master_port());
      bauer::bauer_node _servernode(bauer::tcp_socket(), opt.get_ip(), opt.get_port());
      std::string filename = opt.get_filename();
      Slave slave(_servernode,filename);

      if(opt.is_provider_mode()) {
          feedback::log("MODE PROVIDER");
          slave_provider_exec(slave,_master_node);
      } else {
          feedback::log("MODE PASSIVE");
          slave_exec(slave,_master_node);
      }
  }
}
