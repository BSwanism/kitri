#include<stdio.h>
#include<unistd.h>
main(){
  puts("system()전");
  system("ls");
  puts("system()후");
}
