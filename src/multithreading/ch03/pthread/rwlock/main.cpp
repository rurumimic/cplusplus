#include <iostream>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_rwlock_t rwlock = PTHREAD_RWLOCK_INITIALIZER;
pthread_barrier_t barrier;

void *reader(void *arg) {
  pthread_rwlock_rdlock(&rwlock);
  int count = *(int *)arg;

  std::cout << "Reader " << count << std::endl;

  pthread_barrier_wait(&barrier);

  pthread_rwlock_unlock(&rwlock);
  return NULL;
}

void *writer(void *arg) {
  pthread_rwlock_wrlock(&rwlock);
  int count = *(int *)arg;

  std::cout << "Writer " << count << std::endl;

  pthread_rwlock_unlock(&rwlock);
  return NULL;
}

int main(int argc, char *argv[]) {
  pthread_t threads[3];
  int count = 739397;

  pthread_barrier_init(&barrier, NULL, 2);

  for (int i = 0; i < 2; i++) {
    pthread_create(&threads[i], NULL, reader, (void *)&count);
    sleep(i + 1);
  }

  pthread_create(&threads[2], NULL, writer, (void *)&count);

  for (int i = 0; i < 3; i++) {
    pthread_join(threads[i], NULL);
  }

  pthread_rwlock_destroy(&rwlock);
  pthread_barrier_destroy(&barrier);
  return 0;
}
