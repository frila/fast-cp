#ifndef __FLAG_ARGUMENTS__
#define __FLAG_ARGUMENTS__

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include "flag_option.hpp"

namespace fcp {
  class flag_arguments {
  protected:
    std::map<std::string, std::string>args;
    bool is_valid_option(std::string opt);
    std::vector<flag_option>accepted_options;
  public:
    void set_arguments(std::map<std::string, std::string>args);
    virtual bool validate_options() {}
  };
}
#endif
