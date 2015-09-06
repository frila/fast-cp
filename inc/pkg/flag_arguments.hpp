#ifndef __FLAG_ARGUMENTS__
#define __FLAG_ARGUMENTS__

#include <iostream>
#include <vector>
#include "flag_option.hpp"

namespace fcp {
  class flag_arguments {
  private:
    const std::vector<flag_option>acceptable_options;
  public:
    virtual bool validate_options() {}
  };
}
#endif
