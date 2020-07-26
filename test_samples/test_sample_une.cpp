#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class PairEven {
public:
    PairEven(int l, int w, int h)
        /* : length(l), width(w), height(h) */
    {
        setLength(l);
        setWidth(w);
        setHeight(h);
    }
    void setLength(int l) {
        if(l>1000) {
            cout << "\nOops l<1000 always ... Aborting ... \n";
            //length=0;
            exit(0);
        } else {
            length=l;
        }
    }
    void setWidth(int w) {
        if(w>1000) {
            cout << "\nOops w<1000 always ... Aborting ... \n";
            //width=0;
            exit(0);
        } else {
            width=w;
        }
    }
    void setHeight(int h) {
        if(h>1000) {
            cout << "\nOops h<1000 always ... Aborting ... \n";
            //height=0;
            exit(0);
        } else {
            height=h;
        }
    }
    double shortest_path() {
        double a = sqrt(pow(length, 2) + pow(height,2)/4);
        double b = sqrt(pow(width, 2) + pow(height,2)/4);
        cout << "a = " << a << "\t b = " << b << endl;
        return a + b;
    }
private:
    // l < 1000
    int length;
    // w < 1000
    int width;
    // h < 1000
    int height;
};


int main() {

    PairEven t(1, 1, 1);
    cout << setprecision(3) << t.shortest_path() << endl;

    PairEven notAllowed(1001, 2, 3);
    cout << endl << setprecision(3) << notAllowed.shortest_path();

    return 0;
}
