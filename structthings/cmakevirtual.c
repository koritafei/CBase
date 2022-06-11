#include <stdio.h>

// 定义指针类型
typedef void (*pf)();

/**
 * @brief 父类
 * */
typedef struct _A {
  pf _f;
} A;

/**
 * @brief 子类
 * */
typedef struct _B {
  A a;  // 子类中定义基类的对象，可以实现对基类的继承
} B;

void FuncA() {
  printf("%s\n", "Base FuncA");
}

void FuncB() {
  printf("%s\n", "Derived FuncB");
}

int main() {
  A a;
  B b;

  a._f   = FuncA;
  b.a._f = FuncB;

  A *pa = &a;
  pa->_f();
  pa = (A *)&b;  // 父类指针指向子类对象
  pa->_f();

  return 0;
}
