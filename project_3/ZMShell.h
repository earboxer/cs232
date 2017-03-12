/**
 * @author: Mitch Stark
 * @author: Zach DeCook
 * @date: 3/10/17
 * @brief: Define the ZM Shell class
 */
#include "ComLine.h"
#include "Path.h"
#include "Prompt.h"
#include <sys/wait.h>
#include <iostream>

class ZMShell {
private:
  Prompt pr;
  Path pa;
  ComLine cl;

public:
  //initialize the shell
  ZMShell() {
    cl.init(std::cin);
  };

  //run the shell
  void run();
};
