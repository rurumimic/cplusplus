#ifndef _APPLY_FOO_H
#define _APPLY_FOO_H

#include <cstdio>

#include "oneapi/tbb.h"

using namespace oneapi::tbb;

void Foo(float& a);

class ApplyFoo {
  float* const my_a;

 public:
  void operator()(const blocked_range<size_t>& r) const {
    float* a = my_a;
    for (size_t i = r.begin(); i != r.end(); ++i) {
      Foo(a[i]);
    }
  }

  void print() const {
    printf("[");
    for (int i = 0; i < 10; i++) {
      printf("%g", my_a[i]);
      if (i < 9) {
        printf(", ");
      }
    }
    printf("]\n");
  }

  ApplyFoo(float a[]) : my_a(a) {}
};

#endif  // !_APPLY_FOO_H
