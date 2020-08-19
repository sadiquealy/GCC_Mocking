#include "Module.h"
#include <pthread.h>
#include <stdio.h>

const unsigned int MOCK_PTHREAD = 1;
extern int __real_pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                                 void *(*start_routine)(void *), void *arg);

unsigned int __wrap_testFun1(unsigned int num) {
  printf("Inside mocked function");
  return num % 10;
}

int __wrap_pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                          void *(*start_routine)(void *), void *arg) {
  printf("calling  mocked pthread_create");
  if (MOCK_PTHREAD)
    return 0; // success
  else
    __real_pthread_create(thread, attr, start_routine, arg);
}
int main() {
  unsigned int num;
  printf("Enter an integer: ");
  scanf("%d", &num);
  printf("\n calling testFunc1  ; result =  %u", testFun1(num));
  printf("\n calling testFunc1 ; result =  %u", testFunc2());
  return 0;
}