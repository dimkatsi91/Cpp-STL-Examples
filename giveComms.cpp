#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <memory>

using namespace std;

#define MAX 128

class Commands {
public:
    Commands() {};
    explicit Commands(const char* pac) : packet(pac) {}
    ~Commands() { delete packet; }
    /* Run a command from C++ Program */
    void install( ) {
        char buffer[MAX];
        const char* off = "sudo apt-get install ";
        strncpy(buffer, off, sizeof(buffer));
        strncat(buffer, packet, sizeof(buffer));
        system(buffer);
    }
    void run(const char* comm) {
        system(comm);
    }
private:
    const char* packet;
};

// Create a Firewall for a Linux machine | PC
// If no iptables installed install --> sudo apt install iptables-persistent
class Firewall : public enable_shared_from_this<Firewall> {
public:
    Firewall() {}
    ~Firewall() {}
    void Rules() {
        Commands C1;
        /* Flush all iptables Netfilter rules for start */
        cout << "Flush: \n";
        C1.run("sudo iptables -F");
        /* Accept ssh connection from 192.168.1.7 host machine */
        cout << "Whitelist \n";
        C1.run("sudo iptables -I INPUT 1 -p tcp -s 192.168.1.7 --dport 22 -j ACCEPT");
        /* DROP | REJECT all other ssh attempts for conenction | REJECT better to send a message of rejection too */
        cout << "Reject all else: \n";
        C1.run("sudo iptables -I INPUT 2 -p tcp --dport 22 -j REJECT");
    }
    void SaveV4Rules() {
        Commands C2;
        C2.run("sudo iptables-save > /etc/iptables/rules.v4");
    }
    void make() {
        Firewall::Rules();
        Firewall::SaveV4Rules();
    }
private:
    //
};

int main() {

    /* Test my SimpleFirewall setup */
    Firewall* fPtr;
    fPtr->make();

    delete fPtr;

    return 0;

}
