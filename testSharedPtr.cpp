#include <memory>   // shared_ptr memory management

#include "Person.h"

typedef shared_ptr<Person<int, double, double>> PersonPtr;
typedef Person<int, double, double> PersonType1;

int main() {
    /*  
     PersonType1 *pPtr0 = new PersonType1("diman77", "katsi", 27, 80.0, 178.78);
     cout << *pPtr0;
     delete pPtr0;
     */

  /* ----------------- */
  PersonPtr pPtr( new PersonType1("Barack", "Obama", 57, 85, 185.85) );
  cout << *pPtr;

  return 0;
}
