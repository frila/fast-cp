#ifndef __FLAG_COPY__
#define __FLAG_COPY__

#include "flag.hpp"
#include <algorithm>

namespace fcp {
  class flag_copy : public flag {
    private:
      bool validate_arguments();
    public:
      flag_copy() {}
      void exec();
      void print_usage();
  };
}
#endif
