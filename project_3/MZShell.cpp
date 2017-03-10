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

    int status;
    char command[261];
    if (pa.find(commandline.getCommand()) != -1) {
      char* command_dir = (char*)pa.getDirectory(pa.find(commandline.getCommand())).c_str();
      strcat(command_dir, "/");
      strcpy(command, command_dir);
      strcat(command, commandline.getCommand());
      pid_t pid_ps = fork();
      if (pid_ps == 0) {
          execv(command, commandline.getArgVector());
      }

      //behavior we want, just need the print statements
      if (commandline.noAmpersand() && pid_ps == 0) {
        wait(NULL);
      }
    }
  }
}

int main() {
  MZShell m;
  m.run();
}
