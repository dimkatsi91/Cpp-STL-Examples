#include <iostream>
#include <string>
#include <algorithm>

class Test {
  friend std::ostream& operator<<( std::ostream& , const Test& );
public:
  Test(const std::string& str_) : str(str_) {}
  ~Test() {}
  void reverse() {
    str.assign( str.rbegin(), str.rend() );
  }
private:
  std::string str;
};

std::ostream& operator<<( std::ostream& os, const Test& test ) {
  os << test.str << "\n";
}

int main() {

  Test namid("namiD");
  std::cout << namid;
  namid.reverse();
  std::cout << namid;

  return 0;
}
