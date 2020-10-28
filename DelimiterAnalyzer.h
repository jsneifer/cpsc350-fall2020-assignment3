#include <iostream>
#include "GenStack.cpp"

using namespace std;

class DelimiterAnalyzer {
  public:
    DelimiterAnalyzer();
    ~DelimiterAnalyzer();

    void runAnalyzer(string file); //Analyzes delimiters
    int getLineNumber(); // Returns the current line of the file

  private:
    GenStack<char> *delimiters;
    int lineNumber; //Keeps track of current line number
};
