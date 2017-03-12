/*
Written by: Mitch Stark
3/10/17
Purpose: Implement the MZShell class
*/

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

    if ((strcmp(commandline.getCommand(), "cd") == 0) && (commandline.getArgVector()[1] != NULL)) {
      int response = chdir(commandline.getArgVector(1));
      if (response < 0) {
        cerr << "Can't find dir: " << commandline.getArgVector(1) << endl;
      } else {
        pr = Prompt();
      }
      continue;
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
          execve(command, commandline.getArgVector(), NULL);
      } else if (pid_ps == -1) {
          cout << "Fork failure, something went wrong..." << endl;
      } else {
          //parent process
          int status;
          //behavior we want, just need the print statements
          if (commandline.noAmpersand()) {
            waitpid(pid_ps, &status, 0);
          }
      }
    }
  }
}
