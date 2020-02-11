#ifndef BRIDGE_UNE_H
#define BRIDGE_UNE_H

#include <iostream>
#include <string>

using namespace std;

class Complex {
    int real, image;
public:
    ///////////////////////////////////////////////////////////////
    /////
    class ComplexImpl;
    ComplexImpl * complexImpl;
    ////
    ///////////////////////////////////////////////////////////////
    Complex(int, int);
    ~Complex();

    void print();
    int getReal() const;
    int getImage() const;
};

#endif /* bridge_une.h */