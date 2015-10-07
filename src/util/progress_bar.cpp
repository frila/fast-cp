#include "progress_bar.hpp"
#include <stdio.h>

void fcp::progress_bar::print_bar(size_t done, size_t remainder) {
  float progress = (float)done/(remainder+done);

  int barWidth = 70;

  std::cout << "[";
  int pos = barWidth * progress;
  for (int i = 0; i < barWidth; ++i) {
    if (i < pos) std::cout << "=";
    else if (i == pos) std::cout << ">";
    else std::cout << " ";
  }

  std::cout << "] " << int(progress * 100.0) << " %\r" << std::flush;
}
