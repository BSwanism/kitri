#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
main(){
  if(fork()==0){
    execl("/bin/echo","echo","this is","message one",(char*)0);
    printf("exec one failed");
    exit(1);
  }
  printf("Parent progrma ending\n");
}
