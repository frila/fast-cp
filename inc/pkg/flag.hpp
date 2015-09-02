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
    flag(std::string name, std::map<std::string, std::string>args); 
    virtual void exec() = 0;
    virtual void print_usage() = 0;
  };
}
#endif
