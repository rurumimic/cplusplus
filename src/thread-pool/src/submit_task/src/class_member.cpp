#include "class_member.hpp"

#include <chrono>
#include <future>
#include <ios>
#include <iostream>
#include <thread>

#include "BS_thread_pool.hpp"

BS::thread_pool pool;

class flag_class {
 public:
  [[nodiscard]] bool get_flag() const { return flag; }

  void set_flag(const bool new_flag) { flag = new_flag; }

  void set_flag_to_true() {
    pool.submit_task([this] {
          this->set_flag(true);
          (*this).set_flag(true);
        })
        .wait();
  }

 private:
  bool flag = false;
};

int submit_class_member_task() {
  std::cout << "--- submit_class_member_task ---\n";

  flag_class flag_object;
  flag_object.set_flag(true);
  std::cout << std::boolalpha << flag_object.get_flag() << '\n';

  pool.submit_task([&flag_object] { flag_object.set_flag(false); }).wait();
  std::cout << std::boolalpha << flag_object.get_flag() << '\n';

  flag_object.set_flag_to_true();
  std::cout << std::boolalpha << flag_object.get_flag() << '\n';

  return 0;
}
