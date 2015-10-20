//
// Created by fausto on 20/10/15.
//

#include "feedback.hpp"
#include <cstdlib>
#include <ctime>
#include <ctype.h>

namespace fcp{

    std::string time_prefix(){
        std::time_t now = std::time(0);
        std::string str_now = std::ctime(&now);
        str_now = str_now.substr(0,str_now.size()-1);
        return std::string("[") + str_now + std::string("]");
    }

    void feedback::log(std::string msg) {
        std::cout << time_prefix() << " - " << msg << std::endl;
    }

    void feedback::warning(std::string msg) {
        std::cout << "\t*** WARNING *** " << std::endl;
        std::cout << time_prefix() << " - " << msg << std::endl;
    }

    void feedback::error(std::string msg, int code) {
        std::cout << "*** ERROR *** " << std::endl;
        std::cout << time_prefix() << " - " << msg << std::endl;
        std::exit(code);
    }
}