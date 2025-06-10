#include <concepts>
#include <iostream>

template <typename T>
  requires std::integral<T>
std::integral auto add(T a, T b) {
  return a + b;
}

std::integral auto add1(std::integral auto a, std::integral auto b) {
  return a + b;
}

int main() {
  std::cout << "1 + 2 = " << add(1, 2) << std::endl;
  std::cout << "true + true = " << add1(true, true) << std::endl;

  // error: no matching function for call to 'add'
  // note: because 'double' does not satisfy 'integral'
  // std::cout << "1.3 + 3.4 = " << add(1.3, 3.4) << std::endl;

  return 0;
}
