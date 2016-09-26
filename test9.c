#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<dirent.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>
char* dir_name[255];
int mysystem(char* argv){
  if(fork()==0){
    DIR *dir;
    struct dirent *pde;
    struct stat buf;
    int count=0,i=0,cnt=0;
    memset(dir_name,'\0',sizeof(dir_name));
    memset(&pde,'\0',sizeof(pde));
    memset(&buf,'\0',sizeof(buf));
    if((dir=opendir(argv))<0)
      {
	perror("opendir error");
	exit(12);
      }
    chdir(argv);
    while(((pde=readdir(dir))!=NULL)){
      lstat(pde->d_name,&buf);
      if(S_ISDIR(buf.st_mode))
	{
	  if(!strcmp(pde->d_name,".")||!strcmp(pde->d_name,".."))
	    {
	      continue;
	    }
	  else{
	    dir_name[count]=pde->d_name;
	    count=count+1;
	  }
	}
      printf("%s\t",pde->d_name);
      if(cnt==6)printf("\n");
      cnt=cnt+1;
    }
  }  
}
main(int argc, char* argv[]){
  mysystem(argv[1]);
}
