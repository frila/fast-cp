#ifndef __FLAG_REPLICATE__
#define __FLAG_REPLICATE__

#include "flag.hpp"
#include "replicate_option.hpp"
#include "progress_bar.hpp"
#include "slave.hpp"

namespace fcp {
  class flag_replicate : public flag {
    private:
      replicate_option opt;
      void print_usage();
      void master_exec();
      void slave_exec(Slave &slave, bauer::bauer_node &_master_node);
      void slave_provider_exec(Slave &slave, bauer::bauer_node &_master_node);
    public:
      flag_replicate(): flag() {}
      void set_arguments(std::map<std::string, std::string> arguments);
      void exec();
  };
}
#endif
