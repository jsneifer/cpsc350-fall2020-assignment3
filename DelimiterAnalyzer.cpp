#include <string>
#include <fstream>
#include <stdlib.h>
#include "DelimiterAnalyzer.h"

using namespace std;

DelimiterAnalyzer::DelimiterAnalyzer() {
  delimiters = new GenStack<char>();
  lineNumber = 1;
}

DelimiterAnalyzer::~DelimiterAnalyzer() {
  delimiters->~GenStack();
}

int DelimiterAnalyzer::getLineNumber() {

}

void DelimiterAnalyzer::runAnalyzer(string file) {
  string tp;
  ifstream cppFile;
  cppFile.open(file);
  if(cppFile.is_open()) {
    // Loops through the file
    while(getline(cppFile, tp)) {
      for(int i = 0; i < tp.size(); ++i) {

        //Checks if character is an opening delimiter
        if(tp[i] == '(' || tp[i] == '[' || tp[i] == '{') {
          delimiters->push(tp[i]);
        //Checks if character is a closing delimiter
        } else if(tp[i] == ')' || tp[i] == ']' || tp[i] == '}') {
          // If stack contains no opening delimiters, so isEmpty == True
          if(delimiters->isEmpty()) {
            cout << "No previous open delimiters" << endl;

            //Check which opening delimiter is required
            if(tp[i] == ')') {
              cout << "Missing opening ( ";
            } else if(tp[i] == ']') {
              cout << "Missing opening [ ";
            } else {
              cout << "Missing opening { ";
            }
            cout << "at line " << lineNumber << endl;
            exit(0);
          //Checks if closing delimter matches opening delimiter
        } else if((tp[i] == ')' && delimiters->peek() == '(') || (tp[i] == ']' && delimiters->peek() == '[') || (tp[i] == '}' && delimiters->peek() == '{')) {
            delimiters->pop();
          //Else statement covers if the closing delimiter does not match top opening
          } else {
            cout << "EXPECTED: ";
            if(delimiters->peek() == '(') {
              cout << ')' << endl;
            } else if(delimiters->peek() == '[') {
              cout << ']' << endl;
            } else if(delimiters->peek() == '{') {
              cout << '}' << endl;
            }
            cout << "FOUND: " << tp[i] << " at line " << lineNumber << endl;
            exit(0);
          }
        }
      }
      lineNumber++;
    }
  }
  cppFile.close();

  //Checks if there are any remaining open delimiters at the end of the file
  if(delimiters->isEmpty()) {
    cout << "Your file has the correct number of delimiters. Good looks. " << endl;
  } else {
    cout << "Reached end of file" << endl;
    while(!delimiters->isEmpty()) {
      if(delimiters->peek() == '(') {
        cout << "MISSING: )" << endl;
        delimiters->pop();
      } else if(delimiters->peek() == '[') {
        cout << "MISSING: ]"<< endl;
        delimiters->pop();
      } else {
        cout << "MISSING: }" << endl;
        delimiters->pop();
      }
    }
    exit(0);
  }
}
