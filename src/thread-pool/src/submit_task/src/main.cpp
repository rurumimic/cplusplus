#include "arguments.hpp"
#include "detach.hpp"
#include "no_arguments.hpp"
#include "wait_for.hpp"

int main() {
  submit_no_arguments_task();
  submit_arguments_task();
  submit_detach_task();
  submit_wait_for_task();

  return 0;
}
