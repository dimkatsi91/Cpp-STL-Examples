/*
 * Prototype Design Pattern deuxieme example 
 * 
 *     < Creational >
 */

#include <iostream>

using namespace std;

enum class RACE {
    FEDERATION,
    KLINGON,
    ANDORIAN,
    KELPIEN
};

// Prototype
class SpaceShip {
public:
    virtual SpaceShip* create() = 0;
    virtual void verify() = 0;
};

// Premier Concrete Prototype
class KlingonShip : public SpaceShip {
public:
    SpaceShip* create() {
        return new KlingonShip;
    }
    void verify() {
        cout << "A Klingon Space Ship was just created ...\n";
    }
};

// Deuxieme Concrete Prototype
class StarFleetShip : public SpaceShip {
public:
    SpaceShip* create() {
        return new StarFleetShip;
    }
    void verify() {
        cout << "A Starfleet Space Ship was just created ...\n";
    }
};

// Troiseme Concrete Prototype
class AndorianShip : public SpaceShip {
public:
    SpaceShip* create() {
        return new AndorianShip;
    }
    void verify() {
        cout << "An Andorian Space Ship was just created ...\n";
    }
};

class SpaceShipOrchestrator {
public:
    static SpaceShip* createShip(const RACE & race) {
        switch(race) {
            case RACE::FEDERATION:
                return new StarFleetShip;
            case RACE::KLINGON:
                return new KlingonShip;
            case RACE::ANDORIAN:
                return new AndorianShip;
            default:
                cout << "Not yet implemented ... \t\tOPTIONS: [FEDERATION | ANDORIAN | KLINGON]\n";
                exit(1);
        }
    }
    ~SpaceShipOrchestrator() { delete ship; }
private:
    static SpaceShip* ship;
};



int main() {

    SpaceShipOrchestrator::createShip(RACE::FEDERATION)->create()->verify();
    SpaceShipOrchestrator::createShip(RACE::ANDORIAN)->create()->verify();
    SpaceShipOrchestrator::createShip(RACE::KLINGON)->create()->verify();
    SpaceShipOrchestrator::createShip(RACE::KELPIEN)->create()->verify();

    return 0;
}
