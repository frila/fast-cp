#ifndef __FLAG_RECV__
#define __FLAG_RECV__

#include "flag.hpp"
#include "recv_options.hpp"
#include "progress_bar.hpp"

namespace fcp {
  class flag_recv : public flag {
    private:
      recv_options opt;
      void print_usage();
    public:
      flag_recv(): flag() {}
      void set_arguments(std::map<std::string, std::string> arguments);
      std::string get_destination();
      void exec();
  };
}
#endif
