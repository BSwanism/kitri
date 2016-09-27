#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#define MSGSIZE 20
main()
{
  int fd[2],pid;
  char msgout[MSGSIZE]="Hello, world\n";
  char msgin[MSGSIZE];
  if(pipe(fd)==-1)
    {
      perror("pipe()");
      exit(1);
    }
  if((pid=fork())>0)
    {
      close(fd[0]);
      write(fd[1],msgout,MSGSIZE);
    }
  else if(pid==0)
    {
      close(fd[1]);
      read(fd[0],msgin,MSGSIZE);
      puts(msgin);
    }
  else
    {
      perror("fork()");
      exit(2);
    }


}
