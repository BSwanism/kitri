#include<sys/types.h>
#include<wait.h>
#include<stdio.h>
#include<stdlib.h>
int main(){
  pid_t pid;
  printf(" I'm the original precess :pid =%d, ppid=%d\n",
	 getpid(),getppid());
  pid=fork();
  if(pid!=0){
    printf("I'm parent process :pid=%d, ppid=%d\n",
	   getpid(),getppid());
    printf("my child process : pid =%d\n",pid);
  }
  else{
    sleep(5);
    printf("I'm child process :pid=%d, ppid=%d\n",
	   getpid(),getppid());
  }
  printf("pid %d terminates.. \n",getpid());
  return 0;
}
