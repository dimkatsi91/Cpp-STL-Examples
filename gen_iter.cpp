#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using std::cout;
using std::endl;
using std::vector;
using std::string;

template<class Itr>
void print(const string& str, Itr start, Itr end) {
  cout << str << endl;
  while( start != end ) {
    cout << *start << endl;
    start++;
  }
}

int main() {

  vector<string> languages{"C++", "Perl", "Ruby", "Python"};
  print("Common used Languages: ", languages.begin(), languages.end());

  vector<string>::iterator itr = find(languages.begin(), languages.end(), "C++");
  cout << *itr << " element found at position #: " << itr - languages.begin() << endl;

  vector<string> langs(languages);
  langs.erase( find(langs.begin(), langs.end(), "C++") );
  replace(langs.begin(), langs.end(), "Ruby", "Java");
  print("\nUpdated languages: ", langs.begin(), langs.end());
  return 0;
}
