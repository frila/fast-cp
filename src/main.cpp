#include <iostream>
#include "arg_parser.hpp"

#include "Feedback.hpp"

int main(int argc, char* argv[]) {
  fcp::parsed_flag* pflag = fcp::arg_parser::validate(argc, argv);

  //TODO: try/catch
  fcp::flag* flag = fcp::flag_mapper::flag_by_name(pflag->name);
  flag->set_arguments(pflag->args);
  flag->exec();
}
