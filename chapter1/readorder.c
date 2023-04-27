#include <apue.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char **argv) {
  char buf[MAXLINE]; //输入的命令
  pid_t pid;         //进程标志
  int status;        //进程状态

  printf("%%");
  while (fgets(buf, MAXLINE, stdin) != NULL) { //从输入stdin中读取数据
    if (buf[strlen(buf) - 1] == '\n') {
      buf[strlen(buf) - 1] = 0;
    }
    pid = fork(); // 创建新线程
    if (pid < 0) {
      err_sys("fork error");
    } else if (pid == 0) {
      execlp(buf, buf, (char *)0); //这里跳转
      err_ret("couldn't execute :%s", buf);
      exit(127);
    }

    if ((pid = waitpid(pid, &status, 0)) < 0) {
      err_sys("waitpid error");
    }
    printf("%%");
  }
  exit(0);
}