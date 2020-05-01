#include <iostream>
#include <string>

using namespace std;


class DE {
public:
    string name;
    bool extras_included;
    
    DE(const string name, const bool extras_included) 
        : name(name), extras_included(extras_included) 
    {}
};

class LinuxDistro {
public:
    string name;
    DE *de;
    LinuxDistro(const string & name, DE * de)
        : name(name), de(de)
    {}

    LinuxDistro(const LinuxDistro & other)
        : name(other.name), de{ new DE{*other.de} }
    {}

    void info() const {
        cout << "********************************************************\n";
        cout << "Distro Name: " << this->name << "\n"
             << "DE     Name: " << de->name << "\n"
             << "Extras Included : " 
             << ( (de->extras_included == true) ? "YES\n" : "NO\n" ) ;
        cout << "********************************************************\n\n";
    }
};




int main() {

    LinuxDistro debian{"Debian", new DE{"Gnome", true}};
    LinuxDistro arch{debian};
    arch.name = "Arch Linux";
    arch.de->extras_included = false;

    debian.info();
    arch.info();

    return 0;
}