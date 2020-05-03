/*
 * Singleton : Only one instance of a class should be used
 *
 */

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

enum class DE {
    CINAMMON,
    GNOME,
    KDE
};

class LinuxException : exception {
    string error_message;
public:
    LinuxException(const string & error_message)
        : error_message(error_message)
    {}
    const char * what() {
        return error_message.c_str();
    }
};

class Linux {
    string name;
    DE de;
public:
    Linux(const string & name, const DE & de)
        : name(name), de(de)
    {
        static int thresh=0;
        if(++thresh>1) {
            LinuxException error("ERROR: Only 1 Linux Instance allowed!\n");
            cout << error.what();
            exit(1);
        }
        /* Or use a throw directly
        if(++thresh>1)
            throw LinuxException("Message does not matter. Default std::exception message will be printed.");
            // -->> terminate called after throwing an instance of 'char const*' <<--
        */
    }
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


int main() {
    Linux mint("Linux Mint", DE::CINAMMON);
    mint.info();

    Linux debian("Debian 10 Jessie", DE::GNOME);
    debian.info();

    return 0;
}