#include <iostream>

using namespace std;

class A {
public:
    virtual void func() = 0;
};


class B: public A {
public:
    void func() override {
        cout << "B ...\n";
    }
};

class C: public A {
public:
    void func() override {
        cout << "C ...\n";
    }
};


int main() {

    A *b = new B();
    b->func();

    A *c = new C();
    c->func();

    return 0;
}
