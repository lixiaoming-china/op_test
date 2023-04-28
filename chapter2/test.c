#include<apue.h>
#include <stdlib.h>
#include <sys/types.h>
#include<sys/wait.h>

void
pr_exit(int status){
  if(WIFEXITED(status)){
    printf("nomal termination,exit status = %d\n",
    WEXITSTATUS(status));
  }
  else if(WIFSIGNALED(status)){
    printf("abnormal termination,signal number = %d%s\n",
    WTERMSIG(status),
    #ifdef WCOREDUMP
           WCOREDUMP(status) ? "(core file generated)" : "");
    #else
           "");   
    #endif      
  }
  else if(WIFSTOPPED(status)){
    printf("child stopped ,signal number = %d\n",
    WSTOPSIG(status));
  }
}

int 
main(int argc,char**argv){
  pid_t pid;
  int status;

  pid = fork();
  if(pid < 0){
    err_sys("fork error");
  }
  else if(pid == 0){
    exit(0);
  }

  if(wait(&status) != pid){
    err_sys("wait error");
  }
  pr_exit(status);

  pid = fork();
  if(pid < 0){
    err_sys("fork error");
  }
  else if(pid == 0){
    abort();
  }
  if(wait(&status) != pid){
    err_sys("wait error");
  }
  pr_exit(status);

   pid = fork();
  if(pid < 0){
    err_sys("fork error");
  }
  else if(pid == 0){
    status = status / 0;
  }
  if(wait(&status) != pid){
    err_sys("wait error");
  }
  pr_exit(status);
  exit(0);



}