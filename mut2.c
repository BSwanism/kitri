#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<sys/types.h>
#include<stdlib.h>

int thread_args[3]={0,1,2};
void* Thread(void *arg){
  int i;
  for(i=0; i<1000; i++){
    printf("thread %d: %dth iteration \n", *(int*)arg, i);
    sleep(1);
  }
  pthread_exit(0);
}
int main(void){
  int i;
  pthread_t threads[3];
  pthread_attr_t thread_attrs;
  struct sched_param param;
  for(i=0; i<3; i++){
    pthread_attr_init(&thread_attrs);
    pthread_attr_setschedpolicy(&thread_attrs, SCHED_RR);
    pthread_attr_getschedparam(&thread_attrs,&param);
    param.sched_priority=20;
    pthread_attr_setschedparam(&thread_attrs, &param);
    pthread_create(&threads[i],&thread_attrs,(void*(*)(void*))Thread,
		   &thread_args[i]);
  }
}
