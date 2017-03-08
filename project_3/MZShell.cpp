#include "MZShell.h"

void MZShell::run() {
  while(true) {
    cout << pr.get() << endl << "]";
    CommandLine c(std::cin);

    if (strcmp(c.getCommand(), "exit") == 0) {
      return;
    }

    int pid_ps = fork();
    char command[261];
    strcpy(command, "/bin/");
    strcat(command, c.getCommand());
    if (pid_ps == 0) {
        execv(command, c.getArgVector());
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
