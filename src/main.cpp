#include <iostream>
#include "arg_parser.hpp"
#include "flag.hpp"
#include "flag_mapper.hpp"

int main(int argc, char* argv[]) {
  fcp::parsed_flag* pflag = fcp::arg_parser::validate(argc, argv);

  fcp::flag* flag = fcp::flag_mapper::flag_by_name(pflag->name);
  flag->exec();
}
