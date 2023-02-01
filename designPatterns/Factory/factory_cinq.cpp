/* (Creational Patterns -> Factory DP)
 * Factory just provides an interface for creating objects in a superclass
 *  allows subclasses to alter the type of objects that will be created
*/

#include <iostream>

using namespace std;


class Body {
public:
    virtual ~Body() {}
    virtual void create() const = 0;
};

class Earth : public Body {
public:
    void create() const override {
        cout << "Creting Planet Earth ...\n";
    }
};

class Mars : public Body {
public:
    void create() const override {
        cout << "Creating Planet Mars ...\n";
    } 
};

class Uranus : public Body {
public:
    void create() const override {
        cout << "Creating Planet Uranus ...\n";
    } 
};

// essentially the client class
class Creator {
public:
    virtual Body* FactoryMethod() const = 0;
    void une_autre_create() const {
        Body *body = this->FactoryMethod();
        body->create();
        // cout << "Creator class called ..\n";
        delete body;
    }
};


class EarthCreator : public Creator {
public:
    Body *FactoryMethod() const override {
        return new Earth();
    }
};

class MarsCreator : public Creator {
public:
    Body *FactoryMethod() const override {
        return new Mars();
    }
};

class UranusCreator : public Creator {
public:
    Body *FactoryMethod() const override {
        return new Uranus();
    }
};

void middleMan(const Creator &planet_creator) {
    planet_creator.une_autre_create();
}


int main() {

    Creator *p_creator = new EarthCreator();
    middleMan(*p_creator);

    Creator *m_creator = new MarsCreator();
    middleMan(*m_creator);

    Creator *u_creator = new UranusCreator();
    middleMan(*u_creator);

    return 0;
}
