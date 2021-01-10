/*
 * Fluent Builder Design Pattern in C++
 */

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class PlanetBuilder;

class Planet {
public:
    friend class PlanetBuilder;
    static PlanetBuilder create(string, double);
    friend ostream & operator << (ostream &, const Planet &);
private:
    // planet variables
    string name;
    double mass;
    // galaxy variables
    string galaxy_name;
    string star_name;
    string satellite_name;

    Planet(string name_, double mass_)
        : name(name_), mass(mass_)
    {}
};

ostream & operator << (ostream & os, const Planet & planet) {
    os << "Planet Name: " << planet.name << endl
        << "Planet Mass: " << planet.mass << endl
        << "Inside Galaxy: " << planet.galaxy_name << endl
        << "Star's Name: " << planet.star_name << endl
        << "Satellite's Name: " << planet.satellite_name << endl;
    return os;
}

class PlanetBuilder {
    Planet planet;
public:
    PlanetBuilder(string name, double mass) 
        : planet(name, mass)
    {}
    operator Planet() const { return move(planet); }
    PlanetBuilder & exists();
    PlanetBuilder & inGalaxy(string);
    PlanetBuilder & withStar(string);
    PlanetBuilder & withSatellite(string);
};

PlanetBuilder & PlanetBuilder::exists() {
    return *this;
}

PlanetBuilder & PlanetBuilder::inGalaxy(string g_name) {
    planet.galaxy_name = g_name;
    return *this;   // this allows .().() ...
}

PlanetBuilder & PlanetBuilder::withStar(string s_name) {
    planet.star_name = s_name;
    return *this;
}

PlanetBuilder & PlanetBuilder::withSatellite(string sat_name) {
    planet.satellite_name = sat_name;
    return *this;
}

////////////////////////////////////////////////////////////////
PlanetBuilder Planet::create(string name, double mass) {
    return {name, mass};
}
/////////////////////////////////////////////////////////////



int main()
{
    Planet p = Planet::create("Earth", pow(5.972, 24))
        .exists()
            .inGalaxy("Milky Way")
            .withSatellite("Moon")
            .withStar("Sun");

    cout << p;

    return 0;
}

/* OUTPUT Sample ::

    Planet Name: Earth
    Planet Mass: 4.23521e+18
    Inside Galaxy: Milky Way
    Star's Name: Sun
    Satellite's Name: Moon

*/