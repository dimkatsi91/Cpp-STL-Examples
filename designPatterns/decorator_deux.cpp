#include <iostream>
//#include <string>

using namespace std;

// Arch Linux | Pure OS only | This is the Component class (i.e. the Interface)
//
class Arch {
public:
    virtual void install() = 0;
};


// This is the ConcreteComponent
//
class AnarchyLinux : public Arch {
//AnarchyLinux() {}    
public:
    //static AnarchyLinux newEmptyAnarchyLinux() {
    //    return {};
    //}
    void install() override {
        cout << "Installing Anarchy Linux (based on Arch) ...\n";
    }
};

// And now the Decorator itself !
//
class Decorator : public Arch {
    Arch *arch;
public:
    Decorator(Arch * arch) : arch(arch) {}
    virtual void install() {
        arch->install();
        cout << "\nDecorator is decorating ...\n";
    }
};

// More decoration ...
//
class ConcreteDecoratorA : public Decorator {
public:
    ConcreteDecoratorA(Arch * arch) : Decorator(arch) {}
    void install() override {
        Decorator::install();
        cout << "Wireless Drivers installed from ConcreteDecorator-A ...\n";
    }
};

// More ...
//
class ConcreteDecoratorB : public Decorator {
public:
    ConcreteDecoratorB(Arch * arch) : Decorator(arch) {}
    void install() override {
        Decorator::install();
        cout << "Other third parties installed from ConcreteDecorator-B ...\n";
    }
};


// That's it for now
//
int main()
{

    Arch * arch = new ConcreteDecoratorB( new ConcreteDecoratorA( new AnarchyLinux() ) );

    arch->install();

    return 0;
}

/*  OUTPUT ::

Installing Anarchy Linux (based on Arch) ...

Decorator is decorating ...
Wireless Drivers installed from ConcreteDecorator-A ...

Decorator is decorating ...
Other third parties installed from ConcreteDecorator-B ...
*/