/*
 * Virtual Functions: When we have an abstract class which we do not want to be instantiated
 *                    via the creation of an object, all we have to do is to put inside it a 
 *                    pure virtual function.
*/

#include <iostream>
#define PI 3.141593
using namespace std;

class Shape {
public:
    virtual ~Shape() {}
    virtual double area() const = 0;    // <-- here it is, =0 ==> PURE one instruction to the compiler
};

class Circle : public Shape {
public:
    Circle(int r) : radius(r) {}
    double area() const {
        return PI * radius * radius;
    }
private:
    int radius;

};

void test() {
    Shape* circle = new Circle(1);
    cout << "Area of the Circle is :: " << circle->area() << endl;
    free(circle);
    // U CANNOT DO :: Shape * shape2 = new Shape();
}

int main() {

    test();

    return 0;
}
