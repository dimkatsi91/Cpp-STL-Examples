#include <iostream>
#include <string>

using namespace std;

// DesktopEnvironment
enum class DE {
    cinnamon,
    gnome,
    kde
};

class Debian {
    friend class DebianFactory;     // since Debian constructor is not accessible
// just for clarity | not needed at all , already is private
//
private:
    Debian(size_t min_ram, size_t min_disk, DE desktop = DE::cinnamon) 
        : min_ram(min_ram), min_disk(min_disk), desktop(desktop) {}
public:
    friend ostream &operator<<(ostream &os, const Debian &deb) {
        string os_desktop("Cinammon ");
        if(deb.desktop==DE::gnome) { os_desktop="Gnome "; }
        else if (deb.desktop==DE::kde) { os_desktop="KDE "; } 

        os << "Debian " << os_desktop
           << "\nMinimum RAM  : " << deb.min_ram << "GB "
           << "\nMinimum Disk : " << deb.min_disk << "GB\n";
        return os;
    }

    // Desktop environment | Gnome | KDE | Cinnamon (default one for Debian distro | for me!)
    DE desktop;
    size_t min_ram;
    size_t min_disk;
};

class DebianFactory {
public:
    // Pure Debian distro
    //
    static Debian Cinammon(size_t min_ram, size_t min_disk) {
        return {min_ram, min_disk};
    }

    // KDE Debian needs double the size of Cinammon regarding RAM & DISK
    //
    static Debian Kde(size_t min_ram, size_t min_disk) {
        return {2*min_ram, 2*min_disk, DE::kde};
    }
    // GNOME Debian needs triple the size of Cinammon regarding RAM & DISK
    //
    static Debian Gnome(size_t min_ram, size_t min_disk) {
        return {3*min_ram, 3*min_disk, DE::gnome};
    }
};



int main() {

    cout << "*******************************************************\n";
    auto cinOS = DebianFactory::Cinammon(1, 10);
    cout << cinOS;

    cout << "*******************************************************\n";
    // diman KDE on Debian
    auto kdeOS = DebianFactory::Kde(1, 10);
    cout << kdeOS;

    cout << "*******************************************************\n";
    // diman Gnome on Debian
    auto gnomeOS = DebianFactory::Gnome(1, 10);
    cout << gnomeOS;

    cout << "*******************************************************\n";

    return 0;
}