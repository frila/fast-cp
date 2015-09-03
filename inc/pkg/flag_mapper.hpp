#ifndef __FLAG_MAPPER__
#define __FLAG_MAPPER__ 
#include <iostream>
#include <map>
#include "flag.hpp"
#include "flag_copy.hpp"

namespace fcp {
  class flag_mapper {
    private:
    static std::map<std::string, flag*> flags;
    public:
    static flag* flag_by_name(std::string name);
  };
}
#endif
