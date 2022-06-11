#include <stdio.h>

#include <iostream>

/**
 * @brief 函数指针
 * */
typedef void (*func)();

class Base {
public:
  Base()  = default;
  ~Base() = default;

  virtual void func1() {
    std::cout << "Base::func1" << std::endl;
  }

  virtual void func2() {
    std::cout << "Base::func2" << std::endl;
  }

  virtual void func3() {
    std::cout << "Base::func3" << std::endl;
  }
};

class Derived : public Base {
public:
  Derived()  = default;
  ~Derived() = default;

  void func1() override {
    std::cout << "Derived::func1" << std::endl;
  }

  void func2() override {
    std::cout << "Derived::func2" << std::endl;
  }
};

func getAddr(void *obj, unsigned int offset) {
  std::cout << "==================" << std::endl;

  // 64bit 指针地址占8字节，通过*(unsigned long *)obj取出前8个字节，即为vptr
  void *vptr_addr = (void *)*(unsigned long *)obj;

  printf("vptr = %p\n", vptr_addr);

  // 通过vptr访问vtable
  // 虚函数表存储函数指针，每个元素占8字节，
  // 通过vptr + offset 即可得到对应的函数地址
  void *func_addr = (void *)*((unsigned long *)vptr_addr + offset);

  printf("func_addr = %p\n", func_addr);

  return (func)func_addr;
}

int main() {
  Base    ptr;
  Derived d;

  Base *pt = new Derived();
  Base &pp = ptr;
  Base &p  = d;

  std::cout << "基类对象直接调用" << std::endl;
  ptr.func1();
  std::cout << "基类对象调用基类实例" << std::endl;
  pp.func1();
  std::cout << "基类指针指向基类实例并调用虚函数" << std::endl;
  pt->func1();
  std::cout << "基类引用指向派生类实例并调用派生类虚函数" << std::endl;
  p.func1();
  std::cout << "基类引用指向派生类实例并调用基类虚函数" << std::endl;
  p.func3();  // 调用基类的函数

  // 手动查找vptr 和 vtable
  func f1 = getAddr(pt, 0);
  (*f1)();
  func f2 = getAddr(pt, 1);
  (*f2)();

  // 派生类没有实现func3， 其虚函数表中存储基类的实现函数的函数指针，
  // 但在基类的虚函数表存在对应的函数指针
  func f3 = getAddr(pt, 2);
  (*f3)();

  delete pt, pt = nullptr;
}