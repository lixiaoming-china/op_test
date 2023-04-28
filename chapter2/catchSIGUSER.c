#include<apue.h>
#include <signal.h>

static void sig_user(int);

int
main(int argc,char**argv){
  if(signal(SIGUSR1,sig_user) == SIG_ERR){
    err_sys("can't catch SIGUSER1");
  }
  if(signal(SIGUSR2, sig_user) == SIG_ERR){
    err_sys("can't catch SIGUSER2");
  }
  while(1){
    pause();
  }
}

static void
sig_user(int signo){
  if(signo == SIGUSR1){
    printf("received SIGUSER1\n");
  }
  else if(signo == SIGUSR2){
    printf("received SIGUSER2\n");
  }
  else{
    err_dump("received signal %d\n",signo);
  }
}