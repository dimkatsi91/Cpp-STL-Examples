#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <cctype>

using namespace std;

template<class T>
class Encrypt {
private:
  vector<T> data;
public:
  Encrypt() {}
  ~Encrypt() {}
  void setData(vector<T>& dt);
  vector<T> getData() { return data; }
  void encrypt();
  void print(ostream &out);
};

template<class T>
void Encrypt<T>::setData(vector<T> &dt) {
  this->data.assign( dt.begin(), dt.end() );
}

template<class T>
void Encrypt<T>::print(ostream &out) {
  typename vector<T>::iterator start = data.begin();
  while( start != data.end() ) {
    out << *start << " ";
    start++;
  }
  out << endl;
}

template<class T>
void Encrypt<T>::encrypt() {
  typename vector<T>::iterator start = data.begin();
  typename vector<T>::iterator end   = data.end();
  while( 1 ) {
    // method here

    start++;
    if( start == end )
      break;
  }

}

int main() {
  vector<string> message{"diman", "dimkatsi"};

  Encrypt<string> Obj;
  Obj.setData( message );
  Obj.print( cout );
  Obj.encrypt();
  Obj.print( cout );

  return 0;
}
