#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class MyClass {
public:
  MyClass(const string& name_) : name(name_) {}
  ~MyClass() {}
  MyClass(const MyClass& rhs) {
    name = rhs.name;
  }
  MyClass& operator=(const MyClass& rhs) {
    name = rhs.name;
    return *this;
  }
  void talk(std::ostream& out) const {

    out << "Hello, my name is " << name << "!\n";
  }
  operator const char* () const {
	  return name.c_str();
  }
private:
  string name;
};


int main() {
  /* ------------------------------------- */
  MyClass Dimos("Dimos");
  MyClass diman = Dimos;  //copy constructor
  Dimos.talk(cout);

  cout << "Using operator () to print name: " << (const char*) diman << endl;
  /* ---------------------------------- */
  //MyClass Luciano("Luciano");
  //MyClass Giorgio("Giorgio");
  //Luciano = Giorgio;    //assignment operator
  //Luciano.talk();

  return 0;
}
