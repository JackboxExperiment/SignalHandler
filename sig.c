#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>

static void sighandler(int signo) {
  if (signo == SIGINT) {
    int file = open("error.txt", O_WRONLY | O_CREAT, 0666);

    if (file < 0) {
      printf("Failed to Write File\n");
      exit(1);
    }

    write(file, "Program exited due to keyboard interrupt\n", 40);
    close(file);
    exit(0);
  }

  else if (signo == SIGUSR1) {
    printf("Parent pid: %d\n", getppid());
    sleep(1);
  }

}


int main() {
  signal(SIGUSR1, sighandler);
  signal(SIGINT, sighandler);

  while(1) {
    printf("PID of this process: %d\n", getpid());
    sleep(1);
  }

  return 0;
}
