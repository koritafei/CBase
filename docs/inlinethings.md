## `inline`
1. 类中内联
类中定义了的函数是隐式内联函数,声明要想成为内联函数，必须在实现处(定义处)加inline关键字。
2. 实现文件中定义内联函数
inline要起作用,inline要与函数定义放在一起,inline是一种“用于实现的关键字,而不是用于声明的关键字”
内联函数可以提高函数效率，但不是所有的函数都定义为内联函数。
内联函数以代码膨胀为代价，仅消除函数调用的代价。
* 如果函数执行体代码相对于函数执行开销较大，那么效率的收益会减小；
* 每一处内联函数的调用都要复制代码，将使程序的总代码量增大，消耗更多的内存空间。

以下情况不适用内联：
（1）如果函数体内的代码比较长，使得内联将导致内存消耗代价比较高。

（2）如果函数体内出现循环，那么执行函数体内代码的时间要比函数调用的开销大。

虚函数可以是内联函数么？
* 虚函数可以是内联函数，内联是可以修饰函数的，但虚函数表现为多态时不可以内联；
* 内联是在编译期内建议编译器内联，而虚函数的多态性在运行期，编译器无法知道运行时调用那个代码，所以多态虚函数无法内联；
* `inline virtual `唯一可以内联的时候是：编译器知道所调用的对象是哪个类`（如 Base::who()）`，这只有在编译器具有实际对象而不是对象的指针或引用时才会发生。

```cpp
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
```
