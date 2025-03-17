#include "return.hpp"

#include <cstdint>  // std::uint64_t
#include <future>
#include <iostream>
#include <numeric>  // std::reduce
#include <vector>

#include "BS_thread_pool.hpp"

template <typename T>
T sum_future_get(T min, T max) {
  BS::thread_pool pool(10);

  BS::multi_future<T> loop_future = pool.submit_blocks(
      min, max + 1,
      [](const T start, const T end) {
        T block_total = 0;
        for (T i = start; i < end; i++) {
          block_total += i;
        }
        return block_total;
      },
      100);

  T result = 0;

  for (std::future<T>& future : loop_future) {
    result += future.get();
  }

  return result;
}

template <typename T>
T sum_multi_future_get(T min, T max) {
  BS::thread_pool pool(10);

  BS::multi_future<T> loop_future = pool.submit_blocks(
      min, max + 1,
      [](const T start, const T end) {
        T block_total = 0;
        for (T i = start; i < end; i++) {
          block_total += i;
        }
        return block_total;
      },
      100);

  std::vector<T> partial_sums = loop_future.get();

  T result = std::reduce(partial_sums.begin(), partial_sums.end());
  return result;
}

int submit_block_sum() {
  std::cout << "--- submit_block_sum::future_get ---\n";
  std::cout << sum_future_get<std::uint64_t>(1, 1'000'000) << std::endl;

  std::cout << "--- submit_block_sum::multi_future_get ---\n";
  std::cout << sum_multi_future_get<std::uint64_t>(1, 1'000'000) << std::endl;

  return 0;
}
