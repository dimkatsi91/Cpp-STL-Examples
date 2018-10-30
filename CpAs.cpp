#include <iostream>

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
  void talk() const {
    cout << "Hello, my name is " << name << "!\n";
  }
private:
  string name;
};


int main() {
  /* ------------------------------------- */
  MyClass Dimos("Dimos");
  MyClass diman = Dimos;  //copy constructor
  Dimos.talk();
  /* ---------------------------------- */
  MyClass Luciano("Luciano");
  MyClass Giorgio("Giorgio");
  Luciano = Giorgio;    //assignment operator 
  Luciano.talk();

  return 0;
}
