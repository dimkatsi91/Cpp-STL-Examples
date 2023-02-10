/*
 * Virtual Destructors: Destructors of base classes should be virtual 
 * If base class (Shape)'s DTOr is not virtual, then destructor of the base class is only called 
*/

#include <iostream>
using namespace std;

class Shape {
public:
    virtual ~Shape() {
        cout << "Shape class DTOr ..\n";
    }
};

class Circle : public Shape {
public:
    ~Circle() {
        cout << "Circle class DTOr ..\n";
    }
};



int main() {

    Shape* circle = new Circle();
    delete circle;

    return 0;
}
