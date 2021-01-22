/* **********************************************************************
 * Memento Design Pattern dernier exemple
 * 
 *          < Behavioral >
 * 
 * Builder Design Pattern used too (somewhat modified/simplified)
 * 
 *          < Creational >
 * 
 * @ Janvier 23, 2021, Covid année
 * 
 * **********************************************************************/
#include <iostream>

using namespace std;

class PointBuilder;

class PointMemento {
public:
    PointMemento(int x, int y) : x(x), y(y) {}
    explicit PointMemento() : x(0), y(0) {}
    int getX() const { return x; }
    int getY() const { return y; }
private:
    int x, y;
};


// Just a simple 2D Point for Memento DP 
// demostration dans C++ | exemple facile
//
class Point {
public:
    friend class PointBuilder;
    static PointBuilder build(int, int);
    PointMemento *createMemento() {
        return new PointMemento(this->x, this->y);
    }
    void restoreToMemento(PointMemento *mem) {
        this->x = mem->getX();
        this->y = mem->getY();
    }
    Point & setx(int x) { this->x=x; return *this; }
    Point & sety(int y) { this->y=y; return *this; }
    friend ostream & operator <<(ostream &, const Point &);
private:
    int x, y;
    explicit Point() : x(0), y(0) {}
    Point(int x, int y) : x(x), y(y) {}
};

ostream & operator <<(ostream & os, const Point & p) {
    os << "Point: (" << p.x << ", " << p.y << ")\n";
    return os;
}

class PointBuilder {
public:
    PointBuilder() {}
    PointBuilder(int x, int y) : point(x, y) {}
    operator Point() & { return move(point); }
    PointBuilder & setX(int x) { point.x = x; return *this; }
    PointBuilder & setY(int y) { point.y = y; return *this; }
    Point get() {
        return point;
    }
private:
    Point point;
};

PointBuilder Point::build(int x, int y) 
{
    return {x, y};
}


int main() 
{
    // Create premier Point
    //
    PointBuilder pb1(2,3);
    Point p1 = pb1.get();
    cout << p1;

    // Create deuxieme Point
    //
    PointBuilder pb2(9,10);
    Point p2 = pb2.get();

    // keep a snapshot of Point Une
    //
    PointMemento *pm1 = p1.createMemento();

    // Update Point Une
    //
    p1.setx(5).sety(7);

    cout << "Point 1 updated is : " << p1;

    p1.restoreToMemento(pm1);
    cout << "Point 1 restored to Point-1-Memento is :: " << p1;

    cout << "Point 2 :: " << p2;
    p2.restoreToMemento(pm1);
    cout << "Point 2 restored to Point 1 initial configuration is :: " << p2;

    delete pm1;

    return 0;
}
