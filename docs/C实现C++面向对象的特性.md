## 封装
利用`struct`模拟`class`， 利用函数指针，把函数和属性封装到结构体中。
## 继承
结构体嵌套
## 多态
模拟多态，必须保持函数指针变量对齐(在内容上完全一致，而且变量对齐上也完全一致)。否则父类指针指向子类对象，运行崩溃！

```cpp
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
```
