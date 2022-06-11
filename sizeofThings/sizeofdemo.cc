#include <iostream>

class EmptyClass {};

/**
 * @brief 静态数据成员被编译器放在程序的一个global data
 * members中，它是类的一个数据成员，但不影响类的大小。不管这个类产生了多少个实例，还是派生了多少新的类，静态数据成员只有一个实例。静态数据成员，一旦被声明，就已经存在。
 * */
class StaticVarClass {
public:
  char         b;
  virtual void func() {
  }
  static int c;
  static int d;
  static int e;
};

/**
 * @brief 对于包含虚函数的类，不管有多少个虚函数，只有一个虚指针,vptr的大小。
 * */
class VirtualFuncClass {
public:
  virtual void fun() {
  }
  virtual void fun1() {
  }
  virtual void fun2() {
  }
  virtual void fun3() {
  }
};

/**
 * @brief 对于包含虚函数的类，不管有多少个纯虚函数，只有一个虚指针,vptr的大小。
 * */
class InterfaceFuncClass {
public:
  virtual void fun()  = 0;
  virtual void fun1() = 0;
  virtual void fun2() = 0;
  virtual void fun3() = 0;
};

class A {  // 对齐
public:
  char a;
  int  b;
};

/**
 * @brief 此时B按照顺序：
 * char a
 * int b
 * short a
 * long b
 * 根据字节对齐4+4+8+8=24
 *
 * 或编译器优化
 * char a
 * short a
 * int b
 * long b
 * 根据字节对齐2+2+4+8=16
 */
class B : A {
public:
  short a;
  long  b;
};
/**
 * 把A的成员拆开看，char为1，int为4，所以是1+（3）+4+1+（3）=12，（）为字节补齐
 */
class C {
  A    a;
  char c;
};

class A1 {
  virtual void fun() {
  }
};
class C1 : public A {};

class Aa {
  virtual void fun() {
  }
};
class Bb {
  virtual void fun2() {
  }
};
class Cc : virtual public Aa, virtual public Bb {
public:
  virtual void fun3() {
  }
};

int main() {
  std::cout << sizeof(EmptyClass) << std::endl;  // 空类大小为1
  // 16 字节对齐、静态变量不影响类的大小、vptr指针=8
  std::cout << sizeof(StaticVarClass) << std::endl;

  // 8 字节对齐、vptr指针=8
  std::cout << sizeof(VirtualFuncClass) << std::endl;

  // 8 字节对齐、vptr指针=8
  std::cout << sizeof(InterfaceFuncClass) << std::endl;

  std::cout << sizeof(A) << std::endl;  // 8
  std::cout << sizeof(B) << std::endl;  // 16 或 24
  std::cout << sizeof(C) << std::endl;  // 12

  /**
   * @brief 对于虚单函数继承，派生类也继承了基类的vptr，所以是8字节
   */
  std::cout << sizeof(C1) << std::endl;  // 8

  /**
   * @brief 8 8 16  派生类虚继承多个虚函数，会继承所有虚函数的vptr
   */
  std::cout << sizeof(Aa) << " " << sizeof(Bb) << " " << sizeof(Cc)
            << std::endl;
}
