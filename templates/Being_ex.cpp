#include <iostream>
//#include <deque>
#include <string>

using namespace std;

template<class T1, class T2, class T3>
class Being {
private:
    string name;
    T1 age;
    T2 height;
    T3 weight;
public:
    Being(string newName, T1 newAge, T2 newHeight, T3 newWeight)
        : name(newName), age(newAge), height(newHeight), weight(newWeight) {}
    ~Being() {}
    string getName() const { return name; }
    T1 getAge() const { return age; }
    T2 getHeight() const { return height; }
    T3 getWeight() const { return weight; }
    virtual void hello() {
        cout << "Hello WOrld!\n";
    }
};

template<class T1, class T2, class T3>
class Person : public Being<T1,T2,T3> {
private:
    string city;
public:
    Person(string nm, T1 ag, T2 hg, T3 wg, string newCity)
        : Being<T1, T2, T3>(nm, ag, hg, wg)
    {
        city = newCity;
    }
    ~Person() {}
    void hello()
    {
        cout << "\nName: " << Being<T1,T2,T3>::getName() << "\n"
             << "Age: " << Being<T1,T2,T3>::getAge() << "\n"
             << "Height: " << Being<T1,T2,T3>::getHeight() << "\n"
             << "Weight: " << Being<T1,T2,T3>::getWeight() << "\n"
             << "City:  " << city << "\n\n";
    }
};



int main()
{
    Person<int, double, double> diman("Dimos", 26, 1.78, 78.2, "Agrinio");
    Person<int, double, double> * dim = &diman;
    //diman.hello();
    //dim->hello();

    const int SIZE = 3;
    Person<int, double, double> *arr[SIZE] = {
        new Person<int, double, double> ("Dimos", 26, 1.78, 78.2, "Agrinio"),
        new Person<int, double, double> ("George", 29, 1.70, 89.5, "Agrinio"),
        new Person<int, double, double> ("Andrew", 56, 1.74, 88.4, "Agrinio")
    };

    for(unsigned i=0; i<SIZE; ++i) {
        arr[i]->hello();
    }

    return 0;
}
