#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Exercise2 {
private:
  string str;
public:
  Exercise2( const string& str_ ) : str( str_ ) {}
  ~Exercise2() {}
  string getStr() const { return str; }
  void printRev() {
    vector<char> rstr( str.rbegin(), str.rend() );
    for( auto ch : rstr )
      cout << ch;
    cout << "\n";
  }
  vector<char> getRev() {
    vector<char> rstr( str.rbegin(), str.rend() );
    return rstr;
  }
};


int main(int argc, char** argv ) {

  Exercise2 Obj(argv[1]);
  Obj.printRev();

  Exercise2 Obj2("C++ Programming");
  vector<char> cpp = Obj2.getRev();
  vector<char>::iterator itr = cpp.begin();
  while(itr!=cpp.end()) {
    cout << *itr;
    itr++;
  }
  cout << "\n";

  return 0;
}
