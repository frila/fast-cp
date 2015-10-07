#ifndef __PROGRESS_BAR__
#define __PROGRESS_BAR__

#include <iostream>

namespace fcp {

  class progress_bar {
    public:
    static void print_bar(size_t done, size_t remainder);
  };
}

#endif
