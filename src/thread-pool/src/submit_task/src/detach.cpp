#include "detach.hpp"

#include <chrono>
#include <iostream>
#include <thread>

#include "BS_thread_pool.hpp"

int submit_detach_task() {
  std::cout << "--- submit_detach_task ---\n";

  BS::thread_pool pool;

  int result = 0;

  pool.detach_task([&result] {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << "Detached task\n";
    result = 42;
  });
  pool.wait();
  std::cout << result << '\n';

  return 0;
}
