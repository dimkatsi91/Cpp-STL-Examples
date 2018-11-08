#include <memory>   // shared_ptr memory management

#include "Person.h"


int main() {
  /*
     Person<int, double, double> *pPtr = new Person<int, double, double>("diman77", "katsi", 26, 80.0, 178.78);
     cout << *pPtr;
  */

  /* ----------------- */
  shared_ptr<Person<int, double, double>> pPtr( new Person<int, double, double>("Barack", "Obama", 57, 85, 185.85) );
  cout << *pPtr;

  return 0;
}
