#include <iostream>
#include <typeinfo> // decltype

using namespace std;

template<class T1, class T2>
class Vector {
public:
    Vector(T1 xx, T2 yy) : x(xx), y(yy) {}
    ~Vector() { x=y=0; }
    Vector(const Vector<T1, T2>& other)
        : x(other.x), y(other.y)
    {}
    virtual auto echo() -> decltype(auto) {
        cout << "Vector v = (" << x << ", " << y << ")\n";
    }
private:
    Vector() : x(0), y(0) {}
    T1 x;
    T2 y;
};


int main()
{
    Vector<int,double> v(2.5, 3);
    v.echo();

    Vector<int,double> v2(v);
    v2.echo();

    return 0;
}