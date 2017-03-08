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
