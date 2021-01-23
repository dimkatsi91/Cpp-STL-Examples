/*
 * Singleton : Only one instance can be instantiated/used
 * 
 * Most simple example for demostration purposes
 * 
 * @Janvier 24, 2021 @ covid-year
 * 
 */
#include <iostream>
using namespace std;

class Point {
public:
    static Point & getPoint(int, int);
    Point & setX(int x) {
        this->x = x;
        return *this;
    }
    Point & setY(int y) {
        this->y = y;
        return *this;
    }
    friend ostream & operator <<(ostream &, const Point &);
private:
    int x, y;
    // copy CTor, assignment operator private --> not accessible
    // as well as others || one instance only
    // 
    Point(int x, int y) : x(x), y(y) {}
    Point(const Point &);
    ~Point() {}
    const Point & operator=(const Point &);
};

ostream & operator <<(ostream & os, const Point & p) {
    os << "Point: (" << p.x << ", " << p.y << ")\n";
    return os;
}

Point& Point::getPoint(int x, int y) {
    static Point p_instance(x, y);
    return p_instance;
}


int main() 
{
    // 1st Singleton Point Instance :: Point = (2,3)
    // 
    Point &p1 = Point::getPoint(2, 3);

    // 2nd Singleton Point Instance ?? NO ,, the same Point (by reference, DTor is private as well), 
    // i.e. :: Point-2 == (2, 3)
    //
    Point &p2 = Point::getPoint(4, 5);

    cout << p1 << p2;

    // Update our only instance of Point Singleton class
    // And print them out to verify my words
    //
    p1.setX(11).setY(22);
    cout << p1 << p2;

    return 0;
}

/* Sample Output ::

    Point: (2, 3)
    Point: (2, 3)
    Point: (11, 22)
    Point: (11, 22)

*/
