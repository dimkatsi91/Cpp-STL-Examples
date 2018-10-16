#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using namespace std;

template<class T1, class T2, class T3>
class Person {

template<class A, class B, class C>
friend ostream& operator<<( ostream & os, Person<A,B,C>& p );

template<class A, class B, class C>
friend istream& operator>>( istream & is, Person<A, B, C>& p );

private:
    string fname;
    string lname;
    T1 age;
    T2 weight;
    T3 height;
public:
    Person() : fname(" "), lname(" "), age(10), weight(40.0), height(150.0) {}
    Person(const string& fn, const string& ln, const T1& newAge = 10, const T2& newWeight = 40.0, const T3& newHeight = 150.0)
        : fname(fn), lname(ln), age(newAge), weight(newWeight), height(newHeight)
    {}
    ~Person() {
        //cout << "Person destroyed...\n";
    }
};


template<class A, class B, class C>
ostream& operator<<( ostream& os, Person<A, B, C>& p)
{
    os << "Hello, my name is " << p.fname << " " << p.lname 
        << ".\nI am " << p.age << " y.o. , " << p.weight << " Kgs and " << p.height << " cm's tall.\n";
    return os;
}

template<class A, class B, class C>
istream& operator>>( istream& is, Person<A, B, C>& p )
{
    cout << "Enter first name please: ";
    is >> p.fname;
    cout << "Enter last name please: ";
    is >> p.lname;
    cout << "Enter age please: ";
    is >> p.age;
    cout << "Enter weight please: ";
    is >> p.weight;
    cout << "Enter height please: ";
    is >> p.height;
    return is;
}

#endif /* Person.h */