#include <future>
#include <iostream>

#include "BS_thread_pool.hpp"

int the_answer() { return 42; }

int main() {
  BS::thread_pool pool;
  std::future<int> my_future = pool.submit_task(the_answer);
  std::cout << my_future.get() << '\n';
  return 0;
}
