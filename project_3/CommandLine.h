#include<iostream>
using namespace std;

class CommandLine {
  istream* input_stream;
 public:
  //initialize the class
  CommandLine(std::istream& in) {
    input_stream = &in;
  };
  char* getCommand() const;
  int getArgCount() const;
  char** getArgVector() const;
  bool noAmpersand() const;
};
