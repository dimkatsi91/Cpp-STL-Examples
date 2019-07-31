#include <iostream>
#include <iterator>

using namespace std;

static int count=0;

template<typename T1, typename T2>
class Complex {
  template<typename t1, typename t2>
    friend istream& operator>>( istream& os, Complex<t1, t2>& Cplx );
  template<typename t1, typename t2>
    friend ostream& operator<<( ostream& os, const Complex<t1, t2>& Cplx );
public:
  Complex() : real(0), imag(0) {count++;}
  Complex(T1 real_, T2 imag_) : real(real_), imag(imag_) {count++;}
  ~Complex() {
    cout << "Complex number C" << count-- << " destructor..\n";
  }
  T1 getReal() const { return real; }
  T2 getImag() const { return imag; }
  void setReal(T1 real_) { real=real_; }
  void setImag(T2 imag_) { imag=imag_; }
  Complex<T1, T2> addComplex( const Complex<T1, T2>& Cplx1, const Complex<T1, T2>& Cplx2 ) {
    return Complex(Cplx1.getReal()+Cplx2.getReal(), Cplx1.getImag()+Cplx2.getImag());
  }
  Complex<T1, T2> operator+( Complex<T1, T2>& Cplx ) {
    return Complex<T1, T2>(real+Cplx.real, imag+Cplx.imag);
  }
  /* '*' overload */
  Complex<T1, T2> operator*() {
    return Complex<T1, T2>(this->real, -this->imag);   
  }
  /* '==' overload */
  bool operator==(Complex<T1, T2> &Cplx) {
    return real==Cplx.real && imag==Cplx.imag;
  }
  /* '!=' overload */
  bool operator!=(Complex<T1, T2> &Cplx) {
    return !(*this==Cplx);
  }
  /* '()' overload */
  bool operator()(Complex<T1, T2> &Cplx) {
    return (real==-Cplx.real && imag==-Cplx.imag);
  }
private:
  T1 real;
  T2 imag;
};
template<typename t1, typename t2>
ostream& operator<<( ostream& os, const Complex<t1, t2>& Cplx ) {
  os << Cplx.real << " + " << Cplx.imag << "*J\n";
  return os;
}
template<typename t1, typename t2>
istream& operator>>( istream& is, Complex<t1, t2>& Cplx ) {
  cout << "Enter real part: ";
  is >> Cplx.real;
  cout << "Enter image part: ";
  is >> Cplx.imag;
  return is;
}

template<typename t1, typename t2>
struct Compare {
  bool operator() ( const Complex<t1, t2>& Cplx1, const Complex<t1, t2>& Cplx2 ){
    return ( (Cplx1.getReal() > Cplx2.getReal()) && (Cplx1.getImag() > Cplx2.getImag()) );
  }
};

int main() {

  Complex<int, int> C1;
  Complex<int, int> C2;

  cin >> C1 >> C2;
  //Complex<int, int> C3 = C3.addComplex(C1, C2);
  Complex<int, int> C3 = C1 + C2;
  cout << "C3 = " << C3;

  Complex<int, int> C4(100, 200);
  cout << "C4 = " << C4;

  Compare<int, int> CMP;
  cout << ( CMP(C3, C4) ? "C3>C4\n" : "C3<C4\n" );

  /* -------------- */

  return 0;
}
