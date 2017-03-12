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

    //This code is causing us problems, I have no idea why?
    // if (pa.find(commandline.getCommand()) == -1) {
    //     continue;
    // }

    char command[261];
    char* command_dir = (char*)"/bin"; //(char*)pa.getDirectory(pa.find(commandline.getCommand())).c_str();
    // cout << "here" << flush;
    // strcat(command_dir, "/");
    // cout << "2" << flush;
    strcpy(command, "/bin/");
    strcat(command, commandline.getCommand());

    cout << "command: " << command << endl << endl << endl << flush;

    if (commandline.getArgVector()[1] != NULL) {
        cout << "arguments: " << commandline.getArgVector()[1] << endl << endl << endl << flush;
    }

    pid_t pid_ps = fork();
    int status;

    if (pid_ps == 0) {
        execve(command, commandline.getArgVector(), NULL);
    }


    if (commandline.noAmpersand()) {
      waitpid(pid_ps, &status, 0);
    }
  }
}
