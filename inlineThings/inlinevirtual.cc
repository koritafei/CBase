#include <iostream>

class Base {
public:
  virtual ~Base() = default;

  inline virtual void who() {
    std::cout << "Base" << std::endl;
  }
};

class Derived : public Base {
public:
  inline void who() override {  // 不写inline时，隐式内联
    std::cout << "Derived" << std::endl;
  }
};

int main() {
  Base base;
  base.who();  // 编译期确定调用函数，内联形式

  // 此处的虚函数是通过指针调用的，呈现多态性，需要在运行时期间才能确定，所以不能为内联。
  Base *ptr = new Derived();
  ptr->who();

  // 因为Base有虚析构函数（virtual ~Base() {}），所以 delete
  // 时，会先调用派生类（Derived）析构函数，再调用基类（Base）析构函数，防止内存泄漏。
  delete ptr;
  ptr = nullptr;
}
