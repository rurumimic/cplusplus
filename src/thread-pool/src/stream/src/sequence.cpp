#include "sequence.hpp"

#include <cmath>    // std::sqrt
#include <fstream>  // std::ofstream
#include <iomanip>  // std::setprecision, std::setw
#include <ios>      // std::fixed
#include <iostream>

#include "BS_thread_pool.hpp"

int std_cout_sequence() {
  BS::thread_pool pool;

  std::cout << "--- std_cout_sequence ---\n";
  pool.submit_sequence(0, 5,
                       [](const unsigned int i) {
                         std::cout << "Task no. " << i << " executing.\n";
                       })
      .wait();

  return 0;
}

int sync_out_sequence() {
  /* lifetime: sync_out > pool
   *
   * Always create the BS::synced_stream object
   * before the BS::thread_pool object
   */
  BS::synced_stream sync_out;
  BS::thread_pool pool;

  std::cout << "--- sync_out_sequence ---\n";
  pool.submit_sequence(0, 5,
                       [&sync_out](const unsigned int i) {
                         sync_out.println("Task no. ", i, " executing.");
                       })
      .wait();

  return 0;
}

int flush_sequence() {
  BS::synced_stream sync_out;
  BS::thread_pool pool;

  sync_out.print(std::setprecision(10), std::fixed);

  std::cout << "--- flush_sequence ---\n";
  pool.submit_sequence(0, 16,
                       [&sync_out](const unsigned int i) {
                         sync_out.print("square root of ", std::setw(2), i,
                                        " is ", std::sqrt(i), ".",
                                        BS::synced_stream::endl);
                       })
      .wait();

  return 0;
}

int log_sequence() {
  std::ofstream log_file("task.log");

  BS::synced_stream sync_out(std::cout, log_file);
  BS::thread_pool pool;

  sync_out.print(std::setprecision(10), std::fixed);

  std::cout << "--- log_sequence ---\n";
  pool.submit_sequence(0, 5,
                       [&sync_out](const unsigned int i) {
                         sync_out.println("Task no. ", i, " executing.");
                       })
      .wait();

  sync_out.remove_stream(log_file);
  // sync_out.add_stream(std::cout);

  pool.detach_sequence(5, 10, [&sync_out](const unsigned int i) {
    sync_out.println("Task no. ", i, " executing.");
  });

  pool.wait();

  return 0;
}
