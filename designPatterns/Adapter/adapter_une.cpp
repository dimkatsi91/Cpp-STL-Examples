/*
 * Adapter Design Pattern: Allows objects with incompatible
 *                         interfaces to collaborate
 * 
 * < Structural Pattern >
 * 
 */

#include <iostream>

using namespace std;

class Point {
public:
    Point(int x, int y) : x(x), y(y) {}
    void info() {
        cout << "(" << x << ", " << y << ") ";
    }
private:
    int x, y;
};

class Line {
public:
    Line(Point *start, Point *end)
        : start(start), end(end)
    {}
    Line() {}
    //~Line() { delete start, end; }
    void info() {
        cout << "Start: ";
        start->info();
        cout << "\t\t";
        cout << "End: ";
        end->info();
        cout << "\t\t";
    }
private:
    Point *start, *end;
};

class Rectangle {
public:
    virtual void info() = 0;
};

class classicRectangle : public Rectangle, public Line {
public:
    classicRectangle(Line *length, Line *width)
        : length(length), width(width)
    {}
    classicRectangle() {}
    //~classicRectangle() { delete length, width; }
    void info() {
        cout << "Length:\t\t";
        length->info();
        cout << "\nWidth:\t\t";
        width->info();
    }
protected:
    Line *length, *width;
};

// This is the Adapter
//
class threeD_Rectangle {
public:
    threeD_Rectangle(classicRectangle * rect, Line * height)
        : rect(rect), height(height)
    {}
    void info() {
        rect->info();
        cout << "\nHeight:\t\t";
        height->info();
        cout << endl;
    }
private:
    classicRectangle * rect;
    Line * height;
};



int main() 
{
    threeD_Rectangle *my_3D_rect = new threeD_Rectangle(
            new classicRectangle(
                new Line(new Point(1,2), new Point(3,4)), 
                new Line(new Point(1,2), new Point(5,6))
            ),
            new Line(new Point(3,4), new Point(7,8))
    );

    my_3D_rect->info();

    delete my_3D_rect;

    return 0;
}
