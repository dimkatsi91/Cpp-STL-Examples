#include <iostream>
#include <string>

using namespace std;

class Press {};

// super-class
//
class Button {
public:
    /*  Without Press class usage
    void press(int number) {
        cout << "Button " << number << " just pressed ...\n";
    }
    */
    Press *press(int number) {
        cout << "Button " << number << " just pressed ...\n";
        return new Press();
    }
};


// DO not use inheritance | Just create a pointer to the Button class
// and call only the function we need to invoke, when we need to execute it
//
// stronger encapsulation than inheritance
//
class QPushButton {
private:
    Button * button;
public:
    static QPushButton Factory() { return {}; }
    //void press(int number) {
    Press *press(int number) {
        cout << "\n***************************************************\n";
        cout << "QPushButton ... \n";
        button->press(number);
        cout << "***************************************************\n";
        return new Press();
    }
};


int main() {

    Button bt1;
    bt1.press(7);

    QPushButton qbt1 = QPushButton::Factory();
    qbt1.press(10);

    return 0;
}