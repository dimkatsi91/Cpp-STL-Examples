/*
 * Structural DP : Decorator
*/

#include <iostream>

using namespace std;

class SystemEngineer {
public:
    virtual ~SystemEngineer() {}
    virtual void info() const = 0;
};

class CloudEngineer : public SystemEngineer {
public:
    ~CloudEngineer() {}
    void info() const override {
        cout << "Cloud Engineer .. ";
    }
};

class Decorator : public SystemEngineer {
protected:
    SystemEngineer *se;
public:
    Decorator(SystemEngineer *se)
        : se(se)
    {}
    void info() const override {
        this->se->info();
    }
};

class DevOps : public Decorator {
public:
    DevOps(SystemEngineer *dv) : Decorator(dv) {}
    void info() const override {
        this->se->info();
        cout << "\nwith DevOps tools skills ..";
    }
};

class DevSecOps : public Decorator {
public:
    DevSecOps(SystemEngineer *dsv) : Decorator(dsv) {}
    void info() const override {
        this->se->info();
        cout << "\nwith DevSecOps tools skills ..";
    }
};

void clientCode(SystemEngineer *se) {
    cout << "\n/* ----------------------------------- */\n";
    se->info();
    cout << "\n/* ----------------------------------- */\n";
}

int main() {
    
    SystemEngineer *se = new CloudEngineer;
    clientCode(se);

    SystemEngineer *devops = new DevOps(se);
    clientCode(devops);
    SystemEngineer *devsecops = new DevSecOps(se);
    clientCode(devsecops);
    SystemEngineer *allInOne = new DevSecOps(devsecops);
    clientCode(allInOne);


    free(allInOne);
    free(devsecops);
    free(devops);
    free(se);

    return 0;
}
