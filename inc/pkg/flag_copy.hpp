#ifndef __FLAG_COPY__
#define __FLAG_COPY__

#include "flag.hpp"
#include "copy_options.hpp"

namespace fcp {
  class flag_copy : public flag {
    private:
      copy_options opt;
      bool validate_arguments();
      std::string get_file_to_send();
    public:
      flag_copy(): flag() {}
      void set_arguments(std::map<std::string, std::string> arguments);
      void exec();
      void print_usage();
  };
}
#endif
