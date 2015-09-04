#ifndef __FLAG__
#define __FLAG__

#include <iostream>
#include <map>

namespace fcp {
  typedef std::string flag_name;
  typedef std::map<std::string, std::string> flag_args;

  class flag {
    protected:
    std::string name;
    std::map<std::string, std::string>args;
     
    public:
    flag() {} 
    virtual void exec() {};
    virtual void print_usage() { std::cout << "foooi" << std::endl; }
  };
}
#endif
