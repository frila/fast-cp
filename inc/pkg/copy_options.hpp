#ifndef __COPY_OPTIONS__
#define __COPY_OPTIONS__

#include <iostream>
#include "flag_arguments.hpp"

namespace fcp {
  class copy_options : public flag_arguments {
  public:
    copy_options() {};
    bool validate_options(); 
  };
}
#endif
