#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
int thread_args[3]={0,1,2};
void* Thread(void*arg){
  int i;
  for(i=0; i<3; i++){
    printf("thread %d: %dth iteration\n",*(int*)arg, i);
       sleep(1);
  }
  pthread_exit(0);
}
void main(void)
{
  int i;
  pthread_t threads[3];
  for(i=0; i<3;i++)
    pthread_create(&threads[i],NULL,(void*(*)(void*))Thread,&thread_args[i]);
  pthread_exit(0);
}
