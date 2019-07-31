#include <iostream>
#include <string>
#include <memory>   // shared_ptr mem management

using std::string;
using std::cout;
using std::shared_ptr;

struct ENDL {
  void endl() const {
    cout << std::endl;
  }
};

class MyString {
public:
  MyString(const string& str_) : str(str_) {}
  ~MyString() {}
  void print1() const {
    for(size_t i=0; i<str.size(); i++)
      cout << str.at( i );      //
    Endl.endl();
  }
  void print2() const {
    for(const auto& ch : str)
      cout << ch;
    Endl.endl();
  }
  void print3() const {
    string::const_iterator start = str.begin();
    while( start != str.end() ) {
      cout << *start;
      start++;
    }
    Endl.endl();
  }
  /* append() function */
  void appString(const string& newString) {
    str.append(newString);
  }
  /* substr() function */
  string getString(int name_idx, int name_length) {
    return str.substr(name_idx, name_length);
  }
  /* find() and replace defs */
  /* Replace char1 with char2 character */
  void rep(const char* oldchar, const char* newchar) {
    size_t pos = str.find(oldchar);
    while(pos != string::npos) {
      str.replace(pos, 1, newchar);
      pos = str.find(oldchar, pos++);
    }
  }
private:
  string str;
  ENDL Endl;
};

typedef shared_ptr <MyString> MyStringPtr;

int main() {
  string TEXT("C++ Strings");

  MyString stringObj1(TEXT);
  stringObj1.print1();

  /* Test append member function */
  stringObj1.appString(" 'at' function for safe & controlled access");
  stringObj1.print2();

  MyStringPtr ObjPtr( new MyString("Shared_ptr auto mem management") );
  ObjPtr->print3();

  string CPP = stringObj1.getString(0, 3);  // Cut C++ string from TEXT string
  cout << CPP << "\n";

  stringObj1.rep(" ", "@");
  stringObj1.print3();

  return 0;
}
