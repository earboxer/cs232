#include "MZShell.h"
#include  <stdio.h>
#include  <sys/types.h>
#include  <signal.h>
#include  <sys/ipc.h>
#include  <sys/shm.h>

void MZShell::run() {
  while(true) {
    cout << pr.get() << endl << "]" << flush;
    CommandLine commandline(std::cin);

    if (strcmp(commandline.getCommand(), "exit") == 0) {
      return;
    }

    pid_t pid_ps = fork();
    int status;
    char command[261];
    strcpy(command, "/bin/");
    strcat(command, commandline.getCommand());
    if (pid_ps == 0) {
        execv(command, commandline.getArgVector());
    }

    if (commandline.noAmpersand()) {
      wait(NULL);
    }


    // if (c.noAmpersand) {
    //   //execute normally
    // } else {
    //   //fork process
    // }


  }
}

int main() {
  MZShell m;
  m.run();
}
