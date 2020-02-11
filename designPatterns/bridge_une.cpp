#include "bridge_une.h"

// define ComplexImpl class
//
class Complex::ComplexImpl {
public:
    void print(Complex * complex);
};

// and its method too
//
void Complex::ComplexImpl::print(Complex * complex) {
    cout << " ComplexImpl class ... \n";
    cout << " Y = " << complex->getReal() << " + " << complex->getImage() << "*j\n";
}


// complex constructor
//
Complex::Complex(int real, int image) 
    : real(real), image(image), complexImpl(new ComplexImpl) 
{}

// free resources upon destruction
//
Complex::~Complex() {
    delete complexImpl;
}

int Complex::getReal() const {
    return real;
}

int Complex::getImage() const {
    return image;
}

void Complex::print() {
    complexImpl->print(this);
}

/////////////////
///// MAIN /////
///////////////
int main() {
    // object of a Complex number | nothing special in this early version | exploration of bridge Design Pattern
    //
    Complex cplx_i = Complex(3, 4);
    // cplx_i Complex number is printed through ComplexImpl object print() function ...
    // 
    cplx_i.print();

    return 0;
}