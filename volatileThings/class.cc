/**
 * @file class.cc
 * @author koritafei (koritafei@gmail.com)
 * @brief 类继承关系
 * @version 0.1
 * @date 2020-08-30
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <iostream>

class A {
public:
  int getA() const {
    return a;
  }

  void setA(int a) {
    this->a = a;
  }

protected:
  int a;
};

class B : public A {
public:
  void print() {
    a++;
    std::cout << this->getA() << std::endl;
  }
};
int main(int argc, char **argv) {
  B *b = new B();
  b->print();
  delete b;
}
