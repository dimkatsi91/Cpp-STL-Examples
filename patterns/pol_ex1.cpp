#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* Abstract class | At least one pure virtual function */
class Physics {
public:
    virtual void print()=0;
};

/* Abstract class too */
class Electronics: public Physics {
public:
    virtual void print() {
        cout << "Electronics ..\n";
    }
};

/* too */
class Computers: public Electronics {
public:
    virtual void print() {
        cout << "Computers ..\n";
    }
};

int main()
{
    //vector<Physics> physics;

    Electronics el1;
    Computers cp1;
    el1.print();
    cp1.print();

    Physics *ph1;
    ph1 = &el1;
    ph1->print();

    Physics *physics[2];
    physics[0] = &el1;
    physics[1] = &cp1;
    for( auto& ph: physics)
        ph->print();
 

    return 0;
}