#include <iostream>

using namespace std;

int fact(int num) {
  if(num==1)
    return 1;
  if(num<1)
    return 0;
  else
    return num*fact(num-1);
}

int main() {

  cout << "Number | Factorial\n";
  for(int i=1; i<=10; i++) {
    cout.width(4);
    cout << i << "   | ";
    cout.width(6);
    cout << fact( i ) << "\n";
  }

  return 0;
}
