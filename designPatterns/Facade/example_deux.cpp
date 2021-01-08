/*
 * Facade DP : Deuxieme Exemple
 * 
 */

#include <iostream>

using namespace std;

class Lights {
public:
    void turn_on() {
        cout << "Lights are now turned on ..." << endl;
    }
    void turn_off() {
        cout << "Lights are now turned off ..." << endl;
    }
};

class Firewall {
public:
    void up() {
        cout << "House in Extra Caution mode ... Firewall is now up & Running ..." << endl;
    }
    void down() {
        cout << "House in normal mode ... Firewall is now down ..." << endl;
    }
};

class Heat {
public:
    void warm(int temp) {
        if(temp<15) exit(1);
        cout << "Heating up this House ... Temperature is now " << temp << " Celsius ... " << endl;
    }
    void cold(int temp) {
        if(temp>10) exit(1);
        cout << "Cooling this House out ... Temperature is now " << temp << " Celsius ... " << endl;
    }
};

// This is the Facade class
//
class SmartHome {
public:
    SmartHome(Lights * lights = nullptr,
              Firewall * firewall = nullptr,
              Heat * heat = nullptr)
        {
            this->lights = lights ?: new Lights;
            this->firewall = firewall ?: new Firewall;
            this->heat = heat ?: new Heat;
        }
    ~SmartHome() {
        delete lights, firewall, heat;
    }
    // Out Of House Mode includes next Operations
    //
    void OoH_mode() {
        lights->turn_off();
        firewall->up();
    }
    // In House mode
    //
    void inHouse() {
        lights->turn_on();
        firewall->down();
    }
    // summer mode
    //
    void summer_mode(int temp) {
        heat->cold(temp);
    }
    // winter mode
    //
    void winter_mode(int temp) {
        heat->warm(temp);
    }
private:
    Lights * lights;
    Firewall * firewall;
    Heat * heat;
};

int main() {

    SmartHome * s1 = new SmartHome();

    s1->OoH_mode();

    s1->inHouse();

    s1->winter_mode(27);

    s1->winter_mode(9);

    free(s1);

    return 0;
}