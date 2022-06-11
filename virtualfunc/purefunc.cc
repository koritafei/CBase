#include <iostream>

/**
 * @brief 抽象类
 * */
class A {
public:
  virtual void f() = 0;
  void         gx() {
    std::cout << "call pure func" << std::endl;
    this->f();
  }
};

class B : public A {
public:
  virtual void f() override {
    std::cout << "f" << std::endl;
  }
};

int main() {
  B b;
  b.gx();
}
