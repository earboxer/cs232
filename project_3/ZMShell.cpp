/**
 * @author: Mitch Stark
 * @author: Zach DeCook
 * @date: 3/10/17
 * @brief: Implement the ZM Shell class
 */

#include "ZMShell.h"
#include  <stdio.h>
#include  <sys/types.h>
#include  <signal.h>
#include  <sys/ipc.h>
#include  <sys/shm.h>

void ZMShell::run() {
  //loop continuously until exit
  while(true) {
    cout << pr.get() << endl << "]" << flush;

    cl.reset();

    if (cl.getCommand().compare("exit") == 0) {
      return;
    }


    //check for cd command, if found, then continue to the top of the loop
    if ( ( cl.getCommand().compare("cd") == 0) && (cl.getArgVector()[1] != NULL)) {
      int response = chdir(cl.getArgVector(1));
      if (response < 0) {
        cerr << "Can't find dir: " << cl.getArgVector(1) << endl;
      }
      continue;
    }

    string command;
    //execute a "bin" command
    string command_dir = "/bin";
    command = command_dir + "/" + cl.getCommand();

    char** vec = cl.getArgVector();

    pid_t pid_ps = fork();
    int status;

    if (pid_ps == 0) {
        execve( command.c_str(), vec, NULL );
    }


    if (cl.noAmpersand()) {
      waitpid(pid_ps, &status, 0);
    }
  }
}
