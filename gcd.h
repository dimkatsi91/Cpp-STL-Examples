#ifndef GCD_H
#define GCD_H

#include <iostream>
using std::cout;
using std::endl;


template<class T>
class GCD {
private:
  T a;
  T b;
public:
  GCD(T aa, T bb) : a(aa), b(bb) {}
  ~GCD() {}
  void setA(T aa) { a=aa; }
  void setB(T bb) { b=bb; }
  T getA() const { return a; }
  T getB() const { return b; }
  T gcd();
  T gcd_rec();
};


template<class T>
T GCD<T>::gcd() {
  /* --------------- */
  T x, aa=a, bb=b;
  if( a<b ) return 1;
  while( b!= 0 ) {
    x = b;
    b = a%b;
    a = x;
  }
  cout << "GCD(" << aa << ", " << bb << ") = " << a << endl;
  return a;
}

template<class T>
T GCD<T>::gcd_rec() {
  /* --------------- */
  if( b==0 ) {
    cout << "GCD = " << a << endl;
    return a;
  } else {
      T y=a;
      setA(b);
      setB(y%b);
      gcd_rec();
  }
}

#endif /* gcd.h */
