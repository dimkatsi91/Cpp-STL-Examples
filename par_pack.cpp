#include <iostream>

using namespace std;

template<class T>
void print( ostream& os, T arg ) {  os << arg << "\n"; };

template<class T, class... Args>
void variadic_printer( ostream &os, T arg, Args... args ) {
  cout << arg << " ";
  print( os, args... );
}

main() {
  variadic_printer( cout, "diman77", "Dimos");
}
