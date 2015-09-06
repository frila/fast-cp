#ifndef __FLAG_OPTION__
#define __FLAG_OPTION__

#include <iostream>

namespace fcp {
  typedef struct flag_option {
    std::string name;
    std::string alias;
    bool is_mandatory;
  } flag_option;
}

#endif
