#include "CommandLine.h"
int main() {
  CommandLine c = CommandLine(std::cin);
  char* cmd = c.getCommand();

  cout << cmd << endl;
}