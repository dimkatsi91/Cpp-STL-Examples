#include <iostream>
#include <vector>

using namespace std;

class Vector {
private:
    int x,y,z;
public:
    Vector() : x(0), y(0), z(0) {}
    Vector(int xx, int yy, int zz) 
        : x(xx), y(yy), z(zz) {}
    virtual ~Vector() {}
    /* Overload () op to use below inside Functor's class foo function */
    bool operator()() {
        return (x==y && x==z && y==z);
    }
    void clear() {
        x=y=z=0;
    }
};

class Functor {
private:
    Vector v;
public:
    Functor() {}
    Functor(int a, int b, int c) 
        : v(a,b,c) 
    {}
    ~Functor() { v.clear(); }
    /* Functors simple example using Vector's class overloaded operator () */
    void foo() {
        if( (v)() ) {
            cout << "All values equal ... \n";
        }
        else {
            cout << "Values not equal ... \n";
        }
    }
};


int main() 
{

    Functor f1;
    Functor f2(2,2,2);
    Functor f3(3,4,5);

    f1.foo();
    f2.foo();
    f3.foo();

    return 0;
}