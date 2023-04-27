#include <apue.h>
#include <unistd.h>

#define BUFFSIZE 4096

int main(int argc, char **argv) {
  int len;
  char buf[BUFFSIZE];

  while ((len = read(STDIN_FILENO, buf, BUFFSIZE)) > 0) {
    if (write(STDOUT_FILENO, buf, len) != len) {
      err_sys("write error");
    }
  }
  if (len < 0) {
    err_sys("read error");
  }
  exit(0);
}