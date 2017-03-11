/**
 * @author: Zach DeCook (zjd7)
 * @date: March 6, 2017
 * @brief Prompt.h defines the Prompt class.
 */
 #include <string>
 #include <cstring>
 #include <vector>
 #include <stdio.h>
 #include <stdlib.h>
 #include <dirent.h>
 #include <unistd.h>
 using namespace std;

class Prompt
{
  public:
    Prompt(){ cwd = getcwd(cwdbuf, 255); };
    string get() const{ return cwd; };
  private:
    string cwd;
    char cwdbuf[255];
};
