#include "DelimiterAnalyzer.cpp"
#include <string>
#include <algorithm>

int main(int argc, char** argv) {

  DelimiterAnalyzer *da = new DelimiterAnalyzer();

  da->runAnalyzer(argv[1]);
  cout << "Would you like to enter a new file to analyze? (y/n)" << endl;
  string cont;
  getline(cin, cont);
  transform(cont.begin(), cont.end(), cont.begin(), ::tolower);
  while(cont == "y" || cont == "yes") {
    cout << "Enter a new file to analyze" << endl;
    string newFile;
    getline(cin, newFile);
    da->runAnalyzer(newFile);

    cout << "Would you like to enter a new file to analyze? (y/n)" << endl;
    getline(cin, cont);
  }

  delete da;
  return 0;
}
