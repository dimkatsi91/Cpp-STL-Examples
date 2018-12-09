#include <iostream>

using std::cout;

class Singleton {
private:
  int val;
  static Singleton* SingletonInstance;
  Singleton(int val_ = 0) : val(val_) {}
public:
  static Singleton* get() {
    if(!SingletonInstance)
      SingletonInstance = new Singleton();
    return SingletonInstance;
  }
  void test() {
    cout << "Singleton message...\n";
  }
};

Singleton* Singleton::SingletonInstance = nullptr;


int main() {

  Singleton::get()->test();

	return 0;
}
