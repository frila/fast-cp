#ifndef __FLAG__
#define __FLAG__

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

namespace fcp {
  typedef std::string flag_name;
  typedef std::map<std::string, std::string> flag_args;

  class flag {
    protected:
      std::string name;
      std::map<std::string, std::string>args;

      const std::vector<std::string> accepted_options;

      std::string get_value(std::string opt);
      bool is_present(std::string opt);
      bool is_valid_option(std::string option); 

      virtual bool validate_arguments() {}
    public:
      flag() {} 
      void set_name(std::string name);
      virtual void set_arguments(std::map<std::string, std::string> arguments);

      virtual void exec() {};
      virtual void print_usage() {}
  };
}
#endif
