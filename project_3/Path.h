/**
 * @author: Zach DeCook (zjd7)
 * @date: March 6, 2017
 * @brief pathprompt.cpp defines the Path and Prompt classes.
 */
#include <string>
#include <cstring>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
using namespace std;

class Path
{
  public:
    Path();
    int find( const string& program ) const;
    string getDirectory( int i ) const;
  private:
    vector<string> directories;
};
