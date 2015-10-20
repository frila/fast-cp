//
// Created by fausto on 20/10/15.
//

#ifndef FAST_CP_FEEDBACK_HPP
#define FAST_CP_FEEDBACK_HPP

#include <iostream>

namespace fcp{
    class Feedback {
    public:
        static void log(std::string);
        static void warning(std::string);
        static void error(std::string,int);
    };
}


#endif //FAST_CP_FEEDBACK_HPP
