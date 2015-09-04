#ifndef __ARG_PARSER__
#define __ARG_PARSER__

#include <iostream>
#include <unistd.h>
#include <getopt.h>
#include "output.hpp"
#include "flag.hpp"
#include "flag_mapper.hpp"

namespace fcp {

  typedef struct parsed_flag {
    std::string name;
    std::map<std::string, std::string>args; 
  } parsed_flag;

  class arg_parser {
  private:
    static bool no_flag(int argc);
    static flag_name flag(char* argv[]);
    static flag_args flag_arguments(int argc, char* argv[]);

  public:
    static parsed_flag* validate(int argc, char* argv[]);
  };
}

#endif
