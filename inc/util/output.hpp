#ifndef __OUTPUT__
#define __OUTPUT__

#include <iostream>

namespace fcp {
  class output {
    public:
    static void print_usage();
    static void print_help(std::string command);   
  };
}

#endif
