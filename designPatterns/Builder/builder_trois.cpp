/*
 * Yet another fluent Builder simple example in C++
 *  jff ... enjoy ...
 */

#include <iostream>
#include <string>

using namespace std;

////////////////////////
class HouseBuilder;
////////////////////////

///////////////////////////////////////////////////////////////////////////////////
class House {
    // House only information
    int floors, rooms;
    double sq_meters;
    // House's Neighborhood info
    string street;
    int street_no;
    // House's Country/City info
    string city_name, country_name;
    // CTor
    House(int floors, 
            int rooms, 
                double sq_meters)
                    : floors(floors), 
                        rooms(rooms), 
                            sq_meters(sq_meters)
                                {}
public:
    friend class HouseBuilder;
    static HouseBuilder build(int, int, double);
    friend ostream & operator << (ostream & , const House &);
};

ostream & operator << (ostream & os, const House & h)
{
    os << "House square meters : " << h.sq_meters << endl
       << "House floors        : " << h.floors << endl
       << "House rooms         : " << h.rooms << endl
       << "Street              : " << h.street << " "
       << h.street_no << endl
       << "Country             : " << h.country_name << endl
       << "City                : " << h.city_name << endl;
    return os;    
}

///////////////////////////////////////////////////////////////////////////////////
class HouseBuilder {
    House house;
public:
    enum class OPTION {
        city,
        country
    };
    HouseBuilder(int floors, int rooms, double sq_meters)
        : house(floors, rooms, sq_meters)
    {}
    operator House() & { return move(house); }
    HouseBuilder & neighbourhood();
    HouseBuilder & at(string, int);
    HouseBuilder & country();
    HouseBuilder & city();
    HouseBuilder & in(string, const OPTION &);
};

HouseBuilder & HouseBuilder::neighbourhood() {
    return *this;
}

HouseBuilder & HouseBuilder::at(string street, int street_no)
{
    house.street = street;
    house.street_no = street_no;
    return *this;
}

HouseBuilder & HouseBuilder::country() {
    return *this;
}

HouseBuilder & HouseBuilder::in(string name, const OPTION & option) {
    switch(option) {
        case OPTION::country:
            house.country_name = name;
            break;
        case OPTION::city:
            house.city_name = name;
            break;
        default:
            cout << "An unexpected ERROR occured ... Aborting ...\n";
            exit(1);    
    }
    return *this;
}

HouseBuilder & HouseBuilder::city() {
    return *this;
}

///////////////////////////////////////////////////////////////////////////////////
HouseBuilder House::build(int floors, int rooms, double sq_meters) {
    return {floors, rooms, sq_meters};
}
///////////////////////////////////////////////////////////////////////////////////

int main()
{
    House myHouse = House::build(6, 3, 55.75)
                        .neighbourhood()
                            .at("Brazilien Rue", 256)
                        .country()
                            .in("France", HouseBuilder::OPTION::country)
                        .city()
                            .in("Grenoble", HouseBuilder::OPTION::city);

    cout << myHouse;

    return 0;
}

/* Sample Output ::

    House square meters : 55.75
    House floors        : 6
    House rooms         : 3
    Street              : Brazilien Rue 256
    Country             : France
    City                : Grenoble

*/