#ifndef __FLAG_COPY__
#define __FLAG_COPY__

#include "flag.hpp"
#include <algorithm>

namespace fcp {
  class flag_copy : public flag {
    private:
      bool is_valid_option(std::string option);
      bool validate_arguments();
    public:
      void set_arguments(std::map<std::string, std::string> arguments);
      flag_copy() {}
      void exec();
      void print_usage();
  };
}
#endif
