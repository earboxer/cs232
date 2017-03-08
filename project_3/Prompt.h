/**
 * @author: Zach DeCook (zjd7)
 * @date: March 6, 2017
 * @brief Prompt.h defines the Prompt class.
 */
class Prompt
{
  public:
    Prompt(){ cwd = getcwd(cwdbuf, 255); };
    string get() const{ return cwd; };
  private:
    string cwd;
    char* ptr;
    char* cwdbuf;
};
