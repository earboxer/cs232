#include "CommandLine.h"
#include <vector>
#include <sstream>
#include <string>

char* CommandLine::getCommand() const {
  char str[256];
  cout << "made it here" << endl;
  input_stream->getline(str, 256);


  stringstream ss(str);
  string buf;
  vector<string> tokens;
  while (ss >> buf) tokens.push_back(buf);



  return (char*)tokens[0].c_str();
}