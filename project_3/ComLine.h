/*
Written by: Mitch Stark
3/10/17
Purpose: Implement the CommandLine class
*/

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <cstring>
using namespace std;

class ComLine {
  vector<string> tokens;
  istream* stream;
 public:
    ComLine(){};
    int init(std::istream& in){
      stream = &in;
    };

  //gets the first word in the string
  string getCommand() const;

  //gets the number of arguments provided
  int getArgCount() const;

  //gets a pointer to an array of the strings
  char** getArgVector() const;

  //returns a specific word in the vector
  char* getArgVector(int i) const;

  //checks if there is an amperstand in the string
  bool noAmpersand() const;

  void reset();
};
