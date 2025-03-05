#include "wait_for.hpp"

#include <chrono>
#include <future>
#include <iostream>
#include <thread>

#include "BS_thread_pool.hpp"

int submit_wait_for_task() {
  std::cout << "--- submit_wait_for_task ---\n";

  BS::thread_pool pool;

  std::future<int> my_future = pool.submit_task([] {
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    std::cout << "Task finished\n";
    return 42;
  });
  while (true) {
    if (my_future.wait_for(std::chrono::milliseconds(100)) !=
        std::future_status::ready) {
      std::cout << "Waiting for the task to finish...\n";
    } else {
      break;
    }
  }
  std::cout << my_future.get() << '\n';

  pool.detach_task([] {
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    std::cout << "Detached task finished\n";
  });
  while (true) {
    if (!pool.wait_for(std::chrono::milliseconds(100))) {
      std::cout << "Waiting for the detached task to finish...\n";
    } else {
      break;
    }
  }

  return 0;
}
