#include "apply_foo.h"
#include "oneapi/tbb.h"
#include "oneapi/tbb/parallel_for.h"

int main() {
  float a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  ApplyFoo apply_foo(a);

  apply_foo.print();

  parallel_for(blocked_range<size_t>(0, 10, 1), apply_foo);

  apply_foo.print();

  return 0;
}
