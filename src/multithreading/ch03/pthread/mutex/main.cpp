#include <iostream>
#include <pthread.h>
#include <stdlib.h>

#define NUM_THREADS 5

static pthread_mutex_t func_mutex = PTHREAD_MUTEX_INITIALIZER;

void func() {
  pthread_mutex_lock(&func_mutex);

  // Critical section
  // Do something that's not thread-safe
  std::cout << "[func] Thread: '" << pthread_self() << "'" << std::endl;

  pthread_mutex_unlock(&func_mutex);
}

/**
 * @arg pointer to thread argument
 * @return 0 on success, non-zero on error
 */
void* worker(void* arg) {
  // arg is a void pointer
  // cast it to a pointer to an int
  int value = *((int*) arg);

  // More code here
  std::cout << "[worker] Thread: '" << pthread_self() << "', value: '" << value << "'" << std::endl;

  return 0;
}


int main (int argc, char *argv[]) {
  pthread_t threads[NUM_THREADS]; // array of thread identifiers
  int thread_args[NUM_THREADS]; // array of integer thread arguments

  int result_code; // return values from pthread functions

  for (unsigned int i = 0; i < NUM_THREADS; ++i) {
    thread_args[i] = i; // set argument

    // create a thread that will execute 'worker' with argument 'i'
    result_code = pthread_create(&threads[i], 0, worker, (void*)&thread_args[i]);
  }

  for (const auto& thread : threads) {
    result_code = pthread_join(thread, 0); // wait for thread completion
  }

  return 0;
}

