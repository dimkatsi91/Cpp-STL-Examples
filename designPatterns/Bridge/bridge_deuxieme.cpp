/*
 * Bridge DP : Structural Design Pattern
*/

#include <iostream>
#include <vector>

using namespace std;

class CloudPlatform {
public:
    virtual ~CloudPlatform() {}
    virtual void createVM() const = 0;
};

class GCP : public CloudPlatform {
public:
    void createVM() const override {
        cout << "GCP: Creating a Virtual Machine (CE) ...\n";
    }
};

class AWS : public CloudPlatform {
public:
    void createVM() const override {
        cout << "AWS: Creating a Virtual Machine (EC2) ...\n";
    }
};

class Abstraction {
protected:
    CloudPlatform *cloudPlatform;
public:
    Abstraction(CloudPlatform *cloudplatform)
        : cloudPlatform(cloudplatform) 
    {}
    virtual ~Abstraction() {}
    virtual void create() const {
        cout << "Abstraction: Create a VM: \n";
        this->cloudPlatform->createVM();
    }
};

class ExtendedAbstraction : public Abstraction {
public:
    ExtendedAbstraction(CloudPlatform *cloudPlatform, string type)
        : Abstraction(cloudPlatform), type(type)
    {}
    void create() const override {
        cout << "ExtendedAbstraction: Creating a VM using Linux Image of type: " << type << endl;
        this->cloudPlatform->createVM();
    }
private:
    string type;
};

void clientCode(const Abstraction &abstraction) {
    abstraction.create();
}

int main() {

    CloudPlatform *cp = new AWS;
    Abstraction *ab = new Abstraction(cp);
    clientCode(*ab);
    free(cp);
    free(ab);

    cout << "// ---------------------------------------------------- //\n";
    cp = new GCP;
    ab = new ExtendedAbstraction(cp, "Fedora");
    clientCode(*ab);
    free(cp);
    free(ab);

    return 0;
}

/*
 * Abstraction: Create a VM: 
 * AWS: Creating a Virtual Machine (EC2) ...
 * // ---------------------------------------------------- //
 * ExtendedAbstraction: Creating a VM using Linux Image of type: Fedora
 * GCP: Creating a Virtual Machine (CE) ...
*/
