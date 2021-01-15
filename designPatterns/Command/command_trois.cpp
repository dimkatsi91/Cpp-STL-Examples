/*
 * Command Design Pattern : troiseme trivial demonstrational example
 * 
 *           Behavioral Pattern
 */
#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
using namespace std;

enum class ACTION {
    AREA,
    PERIMETER
};

// Interface class
class Command {
public:
    virtual double execute(const ACTION &) = 0;
};

class Point {
public:
    Point(int x, int y) : x(x), y(y) {}
    int getx() { return x; }
    int gety() { return y; }
private:
    int x, y;
};

class Circle : public Point {
public:
    friend ostream & operator <<(ostream &, Circle &);
    Circle(int x, int y, double radius) 
        : Point(x, y), radius(radius) 
    {}
    double get_area() {
        return M_PI*sqrt(radius);
    }
    double get_perimeter() {
        return 2*M_PI*radius;
    }
private:
    double radius;
};

ostream & operator <<(ostream & os, Circle & circle) {
    os << "Circle: (" << circle.getx() << ", " 
        << circle.gety() 
        << ") with Radius: " << circle.radius << " ";
    return os;
}

class CircleCommand : public Command {
public:
    CircleCommand(Circle *circle) : circle(circle) {}
    ~CircleCommand() { delete circle; }
    double execute(const ACTION &action) {
        double res{0};
        switch (action) {
            case ACTION::AREA:
                res = circle->get_area();
                break;
            case ACTION::PERIMETER:
                res = circle->get_perimeter();
                break;
            default:
                cout << "OPTIONS: ACTION::AREA || ACTION::PERIMETER . Aborting ...\n";
                break;
        }
        return res;
    }
private:
    Circle *circle;
};

class Controller {
public:
    void set_cmd(Command *cmd) {
        this->cmd = cmd;
    }
    double execute_cmd(const ACTION & action) {
        return this->cmd->execute(action);
    }
    ~Controller() { delete cmd; }
private:
    Command *cmd;
};


int main()
{
    Circle * circle = new Circle(1, 1, 2.25);

    CircleCommand * area_cmd = new CircleCommand(circle);
    CircleCommand * perim_cmd = new CircleCommand(circle);

    Controller *ctrl = new Controller();

    cout << *circle << endl;

    ctrl->set_cmd(area_cmd);
    cout << "Circle Area is : " << ctrl->execute_cmd(ACTION::AREA) << endl;

    ctrl->set_cmd(perim_cmd);
    cout << "Circle Perimeter is : " << ctrl->execute_cmd(ACTION::PERIMETER) << endl;

    delete circle, area_cmd, perim_cmd, ctrl; 

    return 0;
}
