#include <memory>   // shared_ptr memory management

#include "Person.h"

typedef shared_ptr<Person<int, double, double>> PersonPtr;
typedef Person<int, double, double> PersonType1;

int main() {
  /*
     Person<int, double, double> *pPtr = new Person<int, double, double>("diman77", "katsi", 27, 80.0, 178.78);
     cout << *pPtr;
  */

  /* ----------------- */
  PersonPtr pPtr( new PersonType1("Barack", "Obama", 57, 85, 185.85) );
  cout << *pPtr;

  return 0;
}
