#include <iostream>
#include <string>
#include <vector>

using namespace std;

// linux interface
class Linux {
public:
// Only the 7 best of linux desktop environments
    enum class DE {kde, cinnamon, gnome, mate, xfce, lxde, budgie};
    // 2 pure virtual functions to be implemented by every linux distro
    // just for demonstration
    virtual void install() = 0;
    virtual void upgrade() = 0;
};

// kde neon
class KdeNeon : Linux {
    DE de;
    KdeNeon(DE de) : de(de) {}
public:
    string desktop() {
        switch(de) {
            case DE::kde:
                return "KDE";
                break;
            case DE::cinnamon:
                return "Cinnamon";
                break;
            case DE::gnome:
                return "Gnome";
                break;
            case DE::mate:
                return "Mate";
                break;
            case DE::xfce:
                return "XFCE";
                break;
            case DE::lxde:
                return "LXDE";
                break;
            case DE::budgie:
                return "Budgie";
                break;
            default:
                return "None";
                break;
        }
    }
    void install() override {
        cout << "Installing KDE Neon OS with Desktop Environment "
             << KdeNeon::desktop() << endl;
    }
    void upgrade() override {
        cout << "Upgrading KDE Neon OS with Desktop Environment "
             << KdeNeon::desktop() << endl;
    }
    // factory
    static KdeNeon newKdeNeon(DE de) {
        return {de};
    }
    friend ostream &operator<<(ostream & os, KdeNeon & kde) {
        os << "OS: KDE Neon\n" << "Desktop Environment: " << kde.desktop() << endl;
        return os;
    }
};

class Command {
public:
    virtual void call() = 0;
};

class KdeNeonCommand : Command {
public:
    KdeNeon & kdeNeon;
    enum class Action { install, upgrade } action;
    // constructor
    KdeNeonCommand(KdeNeon & kde, Action action)
        : kdeNeon(kde), action(action)
    {}
    void call() override {
        switch(action) {
            case Action::install:
                kdeNeon.install();
                break;
            case Action::upgrade:
                kdeNeon.upgrade();
                break;
            default:
                cout << "Please specify an action for KdeNeonCommand to execute and try again...\n";
                break;
        }
    }
};


int main() {
    cout << "**********************************************\n";
    KdeNeon kde_une = KdeNeon::newKdeNeon(Linux::DE::kde);
    cout << kde_une;

    cout << "**********************************************\n";
    vector<KdeNeonCommand> commands {
        KdeNeonCommand{kde_une, KdeNeonCommand::Action::install},
        KdeNeonCommand{kde_une, KdeNeonCommand::Action::upgrade}
    };

    for (auto & command : commands) {
        command.call();
    }

    return 0;
}
