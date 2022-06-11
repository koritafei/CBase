#include <iostream>

class A {
private:
  virtual void func() {
    std::cout << "func" << std::endl;
  }

  friend int main();
};

int main() {
  A a;
  a.func();
}
