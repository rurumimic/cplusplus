#include "apply_foo.h"
#include "average.h"
#include "oneapi/tbb.h"
#include "oneapi/tbb/parallel_for.h"
#include "oneapi/tbb/partitioner.h"

using namespace oneapi::tbb;

int main() {
  float a[20002];
  float b[20002];
  for (int i = 0; i < 20002; i++) {
    a[i] = i;
    b[i] = i;
  }

  ApplyFoo apply_foo(a);
  apply_foo.print();
  parallel_for(blocked_range<size_t>(1, 20001), apply_foo, auto_partitioner());
  apply_foo.print();

  for (int i = 0; i < 20002; i++) {
    a[i] = i;
    b[i] = 0;
  }

  Average average(a, b);
  average.print();
  parallel_for(blocked_range<size_t>(1, 20001), average, auto_partitioner());
  average.print();

  return 0;
}
