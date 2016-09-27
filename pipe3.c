#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#define MAXBUFF 1024
void client1(int readfd, int writefd);
void server1(int readfd, int writefd);
int main(void){
  int childpid, pipe1[2], pipe2[2];
  if(pipe(pipe1)<0|| pipe(pipe2)<0)
    printf("pipe error");
  if((childpid=fork())<0)
    printf("fork error");
  else if(childpid>0){
    close(pipe1[0]);
    close(pipe2[1]);
    client1(pipe2[0],pipe1[1]);
    while(wait((int*)0)!=childpid);
    close(pipe1[1]);
    close(pipe2[0]);
    exit(0);
  }else{
    close(pipe1[1]);
    close(pipe2[0]);
    server1(pipe1[0],pipe2[1]);
    close(pipe1[0]);
    close(pipe2[1]);
    exit(0);
  }
}

void client1(int readfd, int writefd){
  char buff[MAXBUFF];
  int n;
  if(fgets(buff,MAXBUFF, stdin)==NULL)
    printf("client: filename read error");
  n=strlen(buff);
  if(buff[n-1]=='\n')
    n--;
  if(write(writefd,buff,n)!=n)
    printf("client :filename write error");
  while((n=read(readfd,buff,MAXBUFF))>0)
    if(write(1,buff,n)!=n)
      printf("client:data write error");
  if(n<0)
    printf("client: data read error");
}
void server1(int readfd, int writefd){
  char buff[MAXBUFF];
  int n,fd; extern int errno;
  if((n=read(readfd,buff,MAXBUFF))<=0)
    printf("server:filename read error");
  buff[n]='\0';
  if((fd=open(buff,0))<0){
    strcat(buff," can't open \n");
    n=strlen(buff);
    if(write(writefd, buff, n)!=n)
      printf("server: errmesg write error");
  }
  else{
    while((n=read(fd,buff,MAXBUFF))>0)
      if(write(writefd,buff,n)!=n)
	printf("server: data write error");
    if(n<0)
      printf("server: read error");
  }
}
