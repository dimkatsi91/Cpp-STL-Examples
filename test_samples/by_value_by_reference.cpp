/*
 * By value or by reference
*/

#include <iostream>
#include <vector>

using namespace std;

enum class PLANET {
    EARTH,
    MARS,
    APOPHIS,
    UNSPECIFIED
};

void by_val(int num) {
    num = num * num;
}

// actual place inside memory/register, so value will be aligned
void by_ref(int *num) {
    *num = *num * *num;
}

void by_value(PLANET planet, PLANET newOne) {
    planet = newOne;
}

void by_reference(PLANET *planet, PLANET *newOne) {
    *planet = *newOne;
}

void print(PLANET &planet) {
    switch (planet)
    {
    case PLANET::EARTH:
        cout << "Planet:: Earth" << endl;
        break;
    case PLANET::MARS:
        cout << "Planet: Mars" << endl;
        break;
    case PLANET::APOPHIS:
        cout <<"Planet: Apophis" << endl;
        break;
    default:
        cout << "Planet: Unspecified | Not yet discovered!\n";
        break;
    }
}

int main() {

    // By value & By reference using integers
    int x = 10;
    by_val(x);
    cout << x << endl;
    by_ref(&x);
    cout << x << endl;

    cout << "**************************************************" << endl;

    // By value and by reference using PLANET's
    PLANET pl = PLANET::UNSPECIFIED;
    by_value(pl, PLANET::EARTH);
    print(pl);
    PLANET pl2 = PLANET::APOPHIS;
    by_reference(&pl, &pl2);
    print(pl);

    return 0;
}

/*
 * 10
 * 100
 * **************************************************
 * Planet: Unspecified | Not yet discovered!
 * Planet: Apophis
*/
