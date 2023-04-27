#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>

/*
1.fork一个子进程，并打印pid，在此过程中父进程不等待。
*/

int 
main(int argc,char**argv){
  pid_t pid; //声明进程
  pid = fork();
  if(pid < 0){  //小于0进行异常处理
    printf("发生错误,fork error");
    exit(1); // 异常退出
  }
  if(pid == 0){ //等于0，子进程的执行
    printf("I am a child , child pid: %d\n",getpid());
    sleep(10); //休眠10秒
  }
  else{ //执行父进程
    wait(NULL);// 等待子进程执行完毕.
    printf("I am a parent,parent pid:%d\n",getpid());
    exit(0);
  }
}