#include <iostream>
#include <string>

using namespace std;

// Interface
class Decorator {
public:
    Decorator(double angle) : angle(angle) {}
    virtual ~Decorator() {}
    virtual void whatever() = 0;
protected:
    double angle;
};

// Another Interface 
template<class T>
class Complex {
public:
    Complex(T *real, T *image)
        : real(real), image(image) {}
    ~Complex() { delete real, image; }
    virtual void echoComplex() = 0;
protected:
    T *real, *image;
};

// IntComplex Implements both interfaces
//
class IntComplex : public Complex<int>, Decorator {
public:
    IntComplex(int *real, int *image, int angle)
        : Complex<int>(real, image), Decorator(angle)
    {}
    void whatever() override {
        cout << "Decorating complex number with an angle of "
             << Decorator::angle << endl;
    }
    void echoComplex() override {
        cout << " Y = " << *this->real << " + " << *this->image << "*J\n";
    }
};


int main() {

    int *real = new int(3);
    int *image = new int(4);
    IntComplex *c1 = new IntComplex(real, image, 10);
    c1->whatever();
    c1->echoComplex();

    delete real, image, c1;

    return 0;
}