#include <iostream>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_key_t key;

void *worker(void *arg) {
  int *value = new int(1);
  pthread_setspecific(key, value);

  int *v = (int *)pthread_getspecific(key);
  *v += 1;

  std::cout << "Thread " << pthread_self() << " value " << *v << std::endl;

  pthread_setspecific(key, 0);
  delete value;
  pthread_exit(NULL);
}

int main(int argc, char *argv[]) {

  pthread_t threads[5];
  pthread_key_create(&key, NULL);

  for (int i = 0; i < 5; i++) {
    pthread_create(&threads[i], NULL, worker, NULL);
  }

  for (int i = 0; i < 5; i++) {
    pthread_join(threads[i], NULL);
  }

  return 0;
}
