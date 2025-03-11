#include "squares.hpp"

#include <cstddef>  // std::size_t
#include <iomanip>  // std::setw
#include <iostream>

#include "BS_thread_pool.hpp"

template <std::size_t N>
struct Squares {
  std::array<std::size_t, N>& squares;
  Squares(std::array<std::size_t, N>& squares) : squares(squares) {}

  void operator()(const std::size_t i) const { squares[i] = i * i; }
};

int submit_squares_lambda() {
  std::cout << "--- submit_squares_lambda ---\n";

  BS::thread_pool pool(10);

  constexpr std::size_t max = 100;
  std::array<std::size_t, max> squares;

  const BS::multi_future<void> loop_future = pool.submit_loop(
      0, max, [&squares](const std::size_t i) { squares[i] = i * i; });

  loop_future.wait();

  for (std::size_t i = 0; i < max; i++) {
    std::cout << std::setw(2) << i << "^2 = " << std::setw(4) << squares[i]
              << ((i % 5 != 4) ? " | " : "\n");
  }

  return 0;
}

int submit_squares_functor() {
  std::cout << "--- submit_squares_functor ---\n";

  BS::thread_pool pool(10);

  constexpr std::size_t max = 100;
  std::array<std::size_t, max> squares;

  Squares<max> squares_functor(squares);

  const BS::multi_future<void> loop_future =
      pool.submit_loop(0, max, squares_functor);

  loop_future.wait();

  for (std::size_t i = 0; i < max; i++) {
    std::cout << std::setw(2) << i << "^2 = " << std::setw(4) << squares[i]
              << ((i % 5 != 4) ? " | " : "\n");
  }

  return 0;
}

int submit_squares_detached() {
  std::cout << "--- submit_squares_detached ---\n";

  BS::thread_pool pool(10);

  constexpr std::size_t max = 100;
  std::array<std::size_t, max> squares;

  Squares<max> squares_functor(squares);

  pool.detach_loop(0, max, squares_functor);

  pool.wait();

  for (std::size_t i = 0; i < max; i++) {
    std::cout << std::setw(2) << i << "^2 = " << std::setw(4) << squares[i]
              << ((i % 5 != 4) ? " | " : "\n");
  }

  return 0;
}
