/*
 * Singleton : Only one instance of a class should be used
 *
 */

#include <iostream>
#include <string>

using namespace std;

enum class DE {
    CINAMMON,
    GNOME,
    KDE
};

class Linux {
protected:
    string name;
    DE de;
    static Linux *linux_instance;
    Linux(const string & name, const DE & de)
        : name(name), de(de)
    {}
public:
    static Linux *getLinuxInstance(const string & name, const DE & de) {
        if(!linux_instance)
            linux_instance = new Linux{name, de};
        return linux_instance;
    }
    void setDE(DE de) { this->de=de; }
    void setName(string name) { this->name=name; }
    Linux(Linux const &) = delete;
    Linux(Linux &&) = delete;
    Linux & operator=(Linux const &) = delete;
    Linux & operator=(Linux &&) = delete;
    void info() const {
        cout << "Distro Name: " << name << "\n"
             << "Desktop Env: ";
        switch(de) {
            case DE::CINAMMON:
                cout << "Cinammon\n";
                break;
            case DE::GNOME:
                cout << "Gnome 3\n";
                break;
            case DE::KDE:
                cout << "Plasma Desktop\n";
                break;
            default:
                cout << "Undefined Desktop\n";
                break;
        }
    }
};


Linux *Linux::linux_instance = nullptr;

int main() {
    Linux * distro = Linux::getLinuxInstance("Linux Mint", DE::CINAMMON);
    distro->info();

    distro->setName("Debian 10 Jessie");
    distro->setDE(DE::GNOME);
    distro->info();

    return 0;
}
/*
    Distro Name: Linux Mint
    Desktop Env: Cinammon
    Distro Name: Debian 10 Jessie
    Desktop Env: Gnome 3
*/