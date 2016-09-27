#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#define MAX_TEXT 128

struct my_msg_st{
  long int my_msg_type;
  char some_text[MAX_TEXT];
};
int main(){
  int running=1;
  int cnt=1,cnt_t=1;
  struct my_msg_st some_data;
  int msgid;
  char buffer[BUFSIZ];
  char buf[100];
  char *t1;
  msgid=msgget((key_t)1234, 0666|IPC_CREAT);
  if(msgid==-1){
    fprintf(stderr,"msgget failed with error: %d\n",errno);
    exit(EXIT_FAILURE);
  }
  while(running){
    sleep(1);
    some_data.my_msg_type=1;
    printf("msg%d\n",cnt);
    sprintf(buf,"%d",cnt);
    strcpy(buffer,"msg");
    strcat(buffer,buf);
    printf("buffer= %s\n",buffer);
    strcpy(some_data.some_text,buffer);
    printf("some_data.some_text= %s\n",some_data.some_text);
    if(msgsnd(msgid,(void*)&some_data,MAX_TEXT,0)==-1){
      fprintf(stderr,"msgsnd failed\n");
      exit(EXIT_FAILURE);
    }
    if(cnt==20){
      running=0;
    }
    cnt++;
  }
}
