#ifndef __FLAG_OPTION__
#define __FLAG_OPTION__

#include <iostream>

namespace fcp {
  typedef struct flag_option {
    std::string name;
    std::string alias;
    bool is_mandatory;
    std::string value;

    flag_option(std::string n, std::string a, bool i): name(n), alias(a), is_mandatory(i) {} 
    void set_value(std::string _value) { value = _value; }
  } flag_option;
}

#endif
