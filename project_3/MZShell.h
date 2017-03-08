#include "CommandLine.h"
#include "Path.h"
#include "Prompt.h"

class MZShell {
private:
  Prompt pr;
  Path pa;

public:
  //initialize the shell
  MZShell();

  //run the shell
  void run();
};
