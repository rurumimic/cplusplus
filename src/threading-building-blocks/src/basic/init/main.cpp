#include <iostream>

#include "oneapi/tbb/global_control.h"

using namespace tbb::detail::d1;
using namespace tbb::detail::r1;

int main() {
  global_control g(global_control::max_allowed_parallelism, 4);

  std::cout << "max_allowed_parallelism: "
            << global_control_active_value(
                   global_control::max_allowed_parallelism)
            << std::endl;

  return 0;
}
