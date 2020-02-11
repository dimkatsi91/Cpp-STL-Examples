#include <iostream>

using namespace std;

// That's the target HOST machine I want to hack
//
class Target {
protected:
    string IP_ADDR;
    bool is_updt_button_clicked;    // The update button which when clicked will update a random app
                                    // in order to get access to that machine | check BeEf Kali Tool!
    Target() 
        : IP_ADDR("XXX.XXX.XXX.XXX"), is_updt_button_clicked(false) 
    {}
    Target(string & ipaddress, bool isMessedUpNow) 
        : IP_ADDR(ipaddress), is_updt_button_clicked(isMessedUpNow) 
    {
        if(startAttack())
            cout << "Sweet\n";
        else
            cout << "Fucked up\n";
    }
public:
    static Target injectTarget(string & ip, bool isFuckedUp) {
        return {ip, isFuckedUp};
    }
    bool startAttack() {
        // Injection functionality after commands to hack or whatever goes here
        // TODO:: OR HAVE IT ALREADY DONE ?? who cares now ...
        cout << "Attack to machine : " << IP_ADDR << " has been initiated ... \n";
        return true;
    }
};

//
class Attack : public Target {
    Attack(string & ip, bool & initiateAttack) {
        Target::injectTarget(ip, initiateAttack);
    }
public:
    static Attack startAttack(string ip, bool start) {
        return {ip, start};
    }
};



int main() {

    Attack attacker = Attack::startAttack("192.168.169.1", true);

    return 0;
}