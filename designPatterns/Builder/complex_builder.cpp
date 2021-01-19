/*
 * A Complex number Builder Design Pattern simple example
 * 
 * @Janvier Dix Neuf, 2021
 * 
 */

#include <iostream>
#include <cmath>

using namespace std;

/* ************************************************************************ */
/* ****************************** Builder DP ***************************** */

/* ****************** */
class ComplexBuilder;
/* ****************** */

enum class COORS_SYSTEM {
    cardasian,
    polar
};

/* ******************************************************************** */
class Complex {
public:
    friend class ComplexBuilder;
    friend ostream & operator <<(ostream &, const Complex &);
    static ComplexBuilder build(int, int);
private:
    Complex(int real, int imag) : real(real), imag(imag) {}
    //Complex() : real(0), imag(0), r(0), theta(0) {}
    int real, imag;
    double r, theta; // theta = tan^-1(imaginary/real) = atan(imag/real)
    COORS_SYSTEM coor_system; // Cardasian (Y = a + b*J) | Polar System (Y = rcos8 + rsin8*J) , r=sqrt(a^2 + b^2)
};

ostream & operator <<(ostream & os, const Complex & c) {
    if(c.imag<0)
        os << "Complex Y = " << c.real << " - " << abs(c.imag) << "*J\n";
    else
        os << "        Y = " << c.real << " + " << c.imag << "\n";
    return os;
}
/* ******************************************************************** */


class ComplexBuilder {
public:
    ComplexBuilder(int real, int imag) : complex(real, imag) {}
    operator Complex() & { return move(complex); }
    ComplexBuilder & set_real(int);
    ComplexBuilder & set_imag(int);
    ComplexBuilder & calc_r();
    ComplexBuilder & calc_theta();
    ComplexBuilder & print(const COORS_SYSTEM &);
private:
    Complex complex;
};


ComplexBuilder & ComplexBuilder::set_real(int real)
{
    complex.real = real;
    return *this;
}

ComplexBuilder & ComplexBuilder::set_imag(int imag)
{
    complex.imag = imag;
    return *this;
}

ComplexBuilder & ComplexBuilder::calc_r()
{
    complex.r = sqrt(pow(this->complex.real,2) + pow(this->complex.imag,2));
    return *this;
}

ComplexBuilder & ComplexBuilder::calc_theta()
{
    complex.theta = atan(double(complex.imag/complex.real));
    return *this;
}

ComplexBuilder & ComplexBuilder::print(const COORS_SYSTEM & coors_option) 
{
    switch(coors_option) {
        case COORS_SYSTEM::cardasian:
            cout << "/* ******************************************************************** */\n";
            cout << "Complex in Cardasian System: \n";
            cout << complex;
            cout << "/* ******************************************************************** */\n\n";
            break;
        case COORS_SYSTEM::polar:
            cout << "/* ******************************************************************** */\n";
            cout << "Complex in Polar System: \n";
            cout << "         Y = r(cos8 + jsin8) = " << complex.r << "*(" << complex.real << " + " << complex.imag << "*J)\n";
            cout << "         Y = " << complex.r*cos(complex.theta) << " + J*" << complex.r*sin(complex.theta) << endl;
            cout << "/* ******************************************************************** */\n\n"; 
            break;
        default:
            cout << "Unspecified Coordinates System .. Aborting ...\n";
            exit(1);
    }
    return *this;
}
/* ******************************************************************** */


/* ******************************************************************** */
ComplexBuilder Complex::build(int real, int imag) 
{
    return {real, imag};
}
/* ******************************************************************** */



int main()
{
    Complex c1 = Complex::build(1, 1).calc_r().calc_theta().print(COORS_SYSTEM::cardasian)
            .set_real(2).set_imag(-3).calc_r().calc_theta().print(COORS_SYSTEM::cardasian)
            .print(COORS_SYSTEM::polar);

    return 0;
}

/* Sample Output ::

    /* ******************************************************************** */
    // Complex in Cardasian System: 
    //        Y = 1 + 1
    /* ******************************************************************** */

    /* ******************************************************************** */
    // Complex in Cardasian System: 
    // Complex Y = 2 - 3*J
    /* ******************************************************************** */

    /* ******************************************************************** */
    // Complex in Polar System: 
    //        Y = r(cos8 + jsin8) = 3.60555*(2 + -3*J)
    //        Y = 2.54951 + J*-2.54951
    /* ********************************************************************
*/

