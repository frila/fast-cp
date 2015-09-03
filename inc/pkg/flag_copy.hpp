#ifndef __FLAG_COPY__
#define __FLAG_COPY__

#include "flag.hpp"

namespace fcp {
  class flag_copy : public flag {
    private:
      std::map<std::string, std::string> arguments;
      bool validate_arguments();
    public:
      flag_copy() {}
      void set_arguments(std::map<std::string, std::string> arguments);
      void exec();
      void print_usage();
  };
}
#endif
