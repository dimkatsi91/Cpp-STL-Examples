
#include "Person.h"

#include <vector>


int main()
{
    Person<int, double, double> diman("Dimos", "Katsimardos");
    
    //cin >> diman;
    //cout << diman;    
    
    
    Person<int, double, double> * Persons[3] = {
        new Person<int, double, double> ("Dimos", "Katsi"),
        new Person<int, double, double> ("Diman", "Katsim"),
        new Person<int, double, double> ("Dim", "Katsim")
    };
    
    
    vector<Person<int, double, double>> persons;
    persons.push_back( Person<int, double, double> ("Dimos", "Katsi", 26, 78.8, 175.4) );
    persons.push_back( Person<int, double, double> ("Diman", "Katsim", 27, 88.8, 180.2) );
    persons.push_back( Person<int, double, double> ("Dim", "Katsim", 28, 98.8, 190.8) );
    
    cout << endl;
    
    vector< Person<int, double, double> >::iterator itr = persons.begin();
    while( itr != persons.end() ) {
        cout << *itr << "\n";
        ++itr;
    }
    
    
    return 0;
}
