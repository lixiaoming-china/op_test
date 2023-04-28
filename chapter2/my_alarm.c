#include<apue.h>
#include<pwd.h>
#include <string.h>
#include <unistd.h>

static void 
my_alarm(int signo){
  struct passwd* rootptr;
  printf("in signal handler\n");
  if((rootptr = getpwnam("root")) == NULL){
    err_sys("getpwnam() error");
  }
  alarm(1);
}

int 
main(int argc,char**argv){
  struct passwd* ptr;
  signal(SIGALRM,my_alarm);
  alarm(1);
  while(1){
    if((ptr = getpwnam("sar")) == NULL){
      err_sys("getpwnam() error");
    }
    if(strcmp(ptr->pw_name,"sar") != 0){
      printf("return value corrupted!,pw_name = %s\n",
      ptr->pw_name);
    }
  }
}