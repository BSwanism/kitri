#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
main(){
  static char *nargv[]={"newpgm","param1","param2","param3",(char*)0};
  printf("this is the original program\n");
  execv("./newpgm",nargv);
  printf("this line should never get printed\n");
}
