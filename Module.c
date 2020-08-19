#include "Module.h"
#include <errno.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

static void *threadFunc(void *arg) {
  printf("Thread Function :: Start");
  // Sleep for 2 seconds
  sleep(2);
  printf("Thread Function:End ");
  return NULL;
}

unsigned int testFun1(const unsigned int num) {
  printf("Inside real function");
  return num % 10;
}

unsigned int testFunc2() {
  // Thread id
  pthread_t threadId;
  // Create a thread that will function threadFunc()
  int err = pthread_create(&threadId, NULL, &threadFunc, NULL);

  // Check if thread is created sucessfuly
  if (err)
    printf("\nThread creation failed :%d ", strerror(err));
  else
    printf("\nThread Created with ID : :%lu", threadId);

  return err;
}