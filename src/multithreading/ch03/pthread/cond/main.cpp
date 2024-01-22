#include <iostream>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define COUNT_TRIGGER 10
#define COUNT_LIMIT 12

int count = 0;
int thread_id[3] = {0, 1, 2};
pthread_mutex_t count_mutex;
pthread_cond_t count_cv; // conditional variable

void *add_count(void *t) {
  int tid = *(int *)t; // cast void* to int* and dereference

  for (int i = 0; i < COUNT_TRIGGER; i++) {
    pthread_mutex_lock(&count_mutex);

    count++; // increment count: critical section
    std::cout << "Counter value: " << count << " Thread ID: " << tid
              << std::endl;

    if (count == COUNT_LIMIT) { // if count reaches limit
      std::cout << "Counter hit limit: " << COUNT_LIMIT << std::endl;
      pthread_cond_signal(&count_cv); // signal waiting thread
    }

    pthread_mutex_unlock(&count_mutex);

    sleep(1); // sleep for 1 second
  }

  pthread_exit(NULL);
}

void *watch_count(void *t) {
  int tid = *(int *)t;

  pthread_mutex_lock(&count_mutex);

  if (count < COUNT_LIMIT) {
    std::cout << "Thread ID: " << tid << " waiting on condition variable"
              << std::endl;
    // spurious wake up: pthread_cond_wait() may return even if no thread
    pthread_cond_wait(&count_cv, &count_mutex);
  }

  std::cout << "Thread ID: " << tid << " Condition variable signal received"
            << std::endl;

  pthread_mutex_unlock(&count_mutex);
  pthread_exit(NULL);
}

int main(int argc, char *argv[]) {

  int tid[3] = {0, 1, 2};

  pthread_t threads[3];
  pthread_attr_t attr;

  pthread_mutex_init(&count_mutex, NULL);
  pthread_cond_init(&count_cv, NULL);

  pthread_attr_init(&attr); // initialize thread attribute
  // PTHREAD_CREATE_JOINABLE: thread can be joined
  // joinable: thread waits for other threads to join
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

  for (int i = 0; i < 2; i++) {
    pthread_create(&threads[i], &attr, add_count, (void *)&tid[i]);
  }

  pthread_create(&threads[2], &attr, watch_count, (void *)&tid[2]);

  for (int i = 0; i < 3; i++) {
    pthread_join(threads[i], NULL);
  }

  pthread_attr_destroy(&attr);
  pthread_mutex_destroy(&count_mutex);
  pthread_cond_destroy(&count_cv);

  return 0;
}
