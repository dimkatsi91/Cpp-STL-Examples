#include <iostream>

using namespace std;

class A {
public:
    virtual void func() = 0;
    virtual ~A() {
        cout << "~A() ...\n";
    }
};


class B: public A {
public:
    void func() {
        cout << "B ...\n";
    }
    ~B() { 
        cout << "~B() ...\n";
    }
};

class C: public A {
public:
    void func() {
        cout << "C ...\n";
    }
    ~C() {
        cout << "~C() ...\n";
    }
};


int main() {

    A *b = new B();
    b->func();

    A *c = new C();
    c->func();

    delete b;
    delete c;

    return 0;
}

// 1st ::
// What is the output ??

// 2nd : Make destrcutor of class A non virtual
// What is the output then ??
//