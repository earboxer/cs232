#include<iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

class CommandLine {
  vector<string> tokens;
 public:
  //initialize the class
  CommandLine(std::istream& in) {
    char* command_string = new char[256];
    in.getline(command_string, 256);

    stringstream ss(command_string);
    string buf;
    while (ss >> buf) tokens.push_back(buf);
  };
  char* getCommand() const;
  int getArgCount() const;
  char** getArgVector() const;
  char* getArgVector(int i) const;
  bool noAmpersand() const;
};
