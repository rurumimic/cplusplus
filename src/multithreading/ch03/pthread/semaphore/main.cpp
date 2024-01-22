#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>

static sem_t sem;

void *reader(void *arg) {
  int value = 0;

  sem_wait(&sem);
  sem_getvalue(&sem, &value);
  std::cout << "Reader: " << value << std::endl;
  sleep(1);
  sem_post(&sem);
  return NULL;
}

int main(int argc, char *argv[]) {

  pthread_t threads[3];

  // 1: initial value of semaphore
  sem_init(&sem, 0, 2);

  for (int i = 0; i < 3; i++) {
    pthread_create(&threads[i], NULL, reader, NULL);
  }

  for (int i = 0; i < 3; i++) {
    pthread_join(threads[i], NULL);
  }

  sem_destroy(&sem);

  return 0;
}
