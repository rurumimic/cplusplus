#include "sequence.hpp"

#include <cstdint>  // std::uint64_t
#include <iostream>
#include <vector>

#include "BS_thread_pool.hpp"

std::uint64_t factorial(const std::uint64_t n) {
  std::uint64_t result = 1;
  for (std::uint64_t i = 2; i <= n; i++) {
    result *= i;
  }
  return result;
}

int submit_sequence_factorial() {
  BS::thread_pool pool;

  constexpr std::uint64_t max = 20;

  BS::multi_future<std::uint64_t> sequence_future =
      pool.submit_sequence(1, max + 1, factorial);

  std::vector<std::uint64_t> factorials = sequence_future.get();

  std::cout << "--- submit_sequence ---\n";
  for (std::uint64_t i = 0; i < max + 1; i++) {
    std::cout << i << "! = " << factorials[i] << std::endl;
  }

  return 0;
}
