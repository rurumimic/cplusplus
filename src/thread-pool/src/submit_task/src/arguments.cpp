#include "arguments.hpp"

#include <chrono>
#include <future>
#include <iostream>
#include <thread>

#include "BS_thread_pool.hpp"

double multiply(const double lhs, const double rhs) { return lhs * rhs; }

int submit_arguments_task() {
  std::cout << "--- submit_arguments_task ---\n";

  BS::thread_pool pool;

  // lambda with arguments
  std::future<double> my_future =
      pool.submit_task([] { return multiply(6, 7); });
  std::cout << my_future.get() << '\n';

  constexpr double lhs = 3;
  constexpr double rhs = 4;
  my_future = pool.submit_task([lhs, rhs] { return multiply(lhs, rhs); });
  std::cout << my_future.get() << '\n';

  return 0;
}
