#include "no_arguments.hpp"

#include <chrono>
#include <future>
#include <iostream>
#include <thread>

#include "BS_thread_pool.hpp"

int the_answer() { return 42; }

int submit_no_arguments_task() {
  std::cout << "--- submit_no_arguments_task ---\n";

  BS::thread_pool pool;

  // function pointer
  std::future<int> my_future = pool.submit_task(the_answer);
  std::cout << my_future.get() << '\n';

  // lambda expression
  my_future = pool.submit_task([] { return 43; });
  std::cout << my_future.get() << '\n';

  // wait for a task to finish
  my_future = pool.submit_task([] {
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    return 44;
  });
  std::cout << "waiting for the task to finish...\n";
  std::cout << my_future.get() << '\n';
  std::cout << "task finished\n";

  return 0;
}
