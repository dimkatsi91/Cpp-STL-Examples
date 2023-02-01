/* (Creational Patterns -> Factory DP)
 * Factory just provides an interface for creating objects in a superclass
 *  allows subclasses to alter the type of objects that will be created
*/

#include <iostream>

using namespace std;

enum class PLANET {
    EARTH,
    MARS,
    URANUS,
};


class Body {
public:
    virtual ~Body() {}
    virtual void print() const = 0;
    static Body *create(PLANET planet);
};

class Earth : public Body {
public:
    void print() const override {
        cout << "Creating Planet Earth ...\n";
    }
};

class Mars : public Body {
public:
    void print() const override {
        cout << "Creating Planet Mars ...\n";
    } 
};

class Uranus : public Body {
public:
    void print() const override {
        cout << "Creating Planet Uranus ...\n";
    } 
};

Body *Body::create(PLANET planet) {
    switch (planet)
    {
    case PLANET::EARTH:
        return new Earth();
        break;
    case PLANET::MARS:
        return new Mars();
        break;
    case PLANET::URANUS:
        return new Uranus();
        break;
    default:
        break;
    }
    return NULL;
};

class MiddleMan {
public:
    MiddleMan(PLANET planet) {
        body = Body::create(planet);
    }
    ~MiddleMan() {
        if (body) {
            delete body;
            body = NULL;
        }
    }
    Body *getBody() {
        return body;
    }
private:
    Body *body;
};


int main() {

    MiddleMan *client = new MiddleMan(PLANET::EARTH);
    Body *terre = client->getBody();
    terre->print();

    client = new MiddleMan(PLANET::MARS);
    Body *mars = client->getBody();
    mars->print();

    client = new MiddleMan(PLANET::URANUS);
    Body *ur = client->getBody();
    ur->print();

    free(client); 

    return 0;
}
