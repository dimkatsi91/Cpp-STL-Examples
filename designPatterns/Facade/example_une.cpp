/*
 * Facade DP: structural design pattern that provides a simplified 
 * (but limited) interface to a complex system of classes, library or framework.
 *
*/

#include <iostream>

using namespace std;

class Subsystem_Une;

template<typename T1, typename T2>
class Complex {
    friend class Subsystem_Une;
public:
    Complex(T1 real, T2 imag)
        : real(real), imag(imag), 
          s1(nullptr)
    {
        //this->s1 = s1 ?: new Subsystem_Une();
    }
    ~Complex() { 
        delete s1;
    }

    Complex<T1, T2> Operation() {
        return this->s1->doubled(*this);
    }
protected:
    T1 real;
    T2 imag;
    Subsystem_Une * s1;
private:
    template<typename t1, typename t2>
        friend ostream& operator<<( ostream& os, const Complex<t1, t2>& Cplx );
};

class Subsystem_Une {
public:
    Subsystem_Une() {}
    template<typename T1, typename T2>
        Complex<T1, T2> doubled(const Complex<T1, T2> & c) {
            return {c.real*2, c.imag*2};
        }
};


template<typename T1, typename T2>
ostream& operator<<( ostream& os, const Complex<T1, T2>& Cplx ) {
  os << Cplx.real << " + " << Cplx.imag << "*J\n";
  return os;
}

int main() {

    Complex<int, int> c1(3, 4);
    
    Complex<int, int> c2 = c1.Operation();

    cout << c1 << c2 << endl;

    return 0;
}