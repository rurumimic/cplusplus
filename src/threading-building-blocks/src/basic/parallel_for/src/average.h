#ifndef _AVERAGE_H
#define _AVERAGE_H

#include <cstdio>

#include "oneapi/tbb.h"

using namespace oneapi::tbb;

struct Average {
  float* input;
  float* output;

 public:
  void operator()(const blocked_range<size_t>& r) const {
    for (size_t i = r.begin(); i != r.end(); ++i) {
      output[i] = (input[i - 1] + input[i + 1] + input[i + 1]) / 3;
    }
  }

  void print() const {
    printf("input: [");
    for (int i = 0; i < 10; i++) {
      printf("%g", input[i]);
      if (i < 9) {
        printf(", ");
      }
    }
    printf(", ...");
    printf("]\n");

    printf("output: [");
    for (int i = 0; i < 10; i++) {
      printf("%g", output[i]);
      if (i < 9) {
        printf(", ");
      }
    }
    printf(", ...");
    printf("]\n");
  }

  Average(float a[], float b[]) : input(a), output(b) {}
};

#endif  // !_AVERAGE_H
