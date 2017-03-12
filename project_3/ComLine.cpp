/**
 * @author: Mitch Stark
 * @author: Zach DeCook
 * @date: 3/10/17
 * @brief: Define the ComLine class
 */
#include "ComLine.h"

string ComLine::getCommand() const {
  if ( tokens.size() > 0 )
    return tokens[0];
  else
    return "pwd";
}

int ComLine::getArgCount() const {
  return tokens.size();
}

char** ComLine::getArgVector() const {
  //return tokens;
  char** arr = new char*[tokens.size() - 1];
  for(int i = 1; i < tokens.size(); i++) {
    if (strcmp(tokens[i].c_str(), "&") != 0) {
        arr[i] = (char*)tokens[i].c_str();
    }

  }
  return arr;
}

char* ComLine::getArgVector(int i) const {
  return (char*)tokens[i].c_str();
}

bool ComLine::noAmpersand() const {
  for(int i = 0; i < tokens.size(); i++) {
    if (tokens[i].find("&") != string::npos) {
      return false;
    }
  }
  return true;
}

void ComLine::reset() {
  
  tokens.clear();
  char command_string[256];
  stream->getline(command_string, 255);

  stringstream ss(command_string);
  string buf;
  while (ss >> buf) tokens.push_back(buf);
}

