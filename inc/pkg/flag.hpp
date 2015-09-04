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
      virtual bool is_valid_option(std::string option) {}
      virtual bool validate_arguments() {}
    public:
      flag() {} 
      void set_name(std::string name);
      virtual void set_arguments(std::map<std::string, std::string> arguments) {
        args = arguments; 
      }
      virtual void exec() {};
      virtual void print_usage() {}
  };
}
#endif
