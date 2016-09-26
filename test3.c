#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
main(){
  printf("this is the origitnal program\n");
  execl("./newpgm","newpgm","param1","param2","param3",(char*) 0);
  printf("this line should never get printed\n");
}
