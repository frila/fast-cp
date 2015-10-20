#include <iostream>
#include "arg_parser.hpp"

#include "feedback.hpp"
#include <exception>

int main(int argc, char* argv[]) {
    try{
        fcp::parsed_flag* pflag = fcp::arg_parser::validate(argc, argv);
        fcp::flag* flag = fcp::flag_mapper::flag_by_name(pflag->name);
        flag->set_arguments(pflag->args);
        flag->exec();
    }catch (std::exception &exception){
        fcp::feedback::error(std::string(exception.what()), 666);
    }
}
