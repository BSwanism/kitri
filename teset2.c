#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<wait.h>
main(){
  pid_t pid;
  pid=fork();
  if(pid!=0){
    while(1) sleep(1000);
  }
  else{
    exit(42);
  }
}
