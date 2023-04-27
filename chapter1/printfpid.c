#include<apue.h>
#include<stdio.h>

int
main(int argc,char**argv){
  printf("Hello world from process ID:%ld\n",(long)getpid());
  return 0;
}