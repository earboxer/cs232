#include "CommandLine.h"

CommandLine::CommandLine(std::istream &in) {
  input_stream = in;
  cout << "Initializing";
}

char* CommandLine::getCommand() const {
  char str[256];
  cout << "made it here";
  cout << str;
}