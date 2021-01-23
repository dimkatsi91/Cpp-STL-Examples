#include <iostream>
#include <string>

using namespace std;

enum class SEX {
    MALE,
    FEMALE,
    UNDEFINED
};

class Person {
public:
    static Person& getPersonInstance(const string & name, const SEX & gendre) {
        static Person personInstance{name, gendre};
        return personInstance;
    }
    void sayHello() {
        cout << "Hello my name is " << name
             << " and I am a ";
        switch(gendre) {
            case SEX::MALE:
                cout << " Male.\n";
                break;
            case SEX::FEMALE:
                cout << " Female.\n";
                break;
            default:
                cout << " Undefined.\n";
                break;
        }
    }
private:
    string name;
    SEX gendre;
    Person(const string & name, const SEX & gendre)
        : name(name), gendre(gendre)
    {}
    ~Person() = default;
    // No copy/move constructors
    //
    Person(const Person &) = delete;
    Person(Person &&) = delete;
    Person& operator=(const Person &) = delete;
    Person& operator=(Person &&) = delete;
};

int main() {

    Person::getPersonInstance("Diman Kaci", SEX::MALE).sayHello();

    return 0;
}