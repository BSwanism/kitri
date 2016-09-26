#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
main()
{
  static char*nargv[]={"newpgm","p1","p2","p3",(char*)0};
  static char *nenv[]={"NAME=VAL","nextname=nextvalu","HOME=/xy",(char*)0};
  printf("this is the original program\n");
  execve("./newpgm",nargv,nenv);
  printf("this line should never get printed\n");
								   
}
