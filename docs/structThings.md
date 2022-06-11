## `C struct`
* `C`仅用作数据的复合类型，只能保存数据，不能放入函数；
* 不能使用`C++`中的权限修饰符；
* 结构体名与函数名相同，可以正常运行并调用。

```cpp
#include <stdio.h>

struct Base {
  // public: 不可使用
  int v1;
  int v2;
  int v3;

  // 不可定义函数
  // void print() {
  //   printf("%d , %d, %d\n", v1, v2, v3);
  // }
};

void Base() {
  printf("%s\n", "Base Func");
}

int main() {
  struct Base b;  // 使用时必须添加struct
  b.v1 = 12;
  b.v2 = 13;
  b.v3 = 14;

  printf("%d , %d , %d\n", b.v1, b.v2, b.v3);

  Base();
}
```

### `c++ struct`
* `C++`结构体中不仅可以定义数据，还可以定义函数。
* `C++`结构体中可以使用访问修饰符，如：`public、protected、private` 。
* `C++`结构体使用可以直接使用不带`struct`。
* `C++`继承
* 若结构体的名字与函数名相同，可以正常运行且正常的调用！但是定义结构体变量时候只能用带`struct`的！

```cpp
#include <iostream>

struct Base {
  int v1;
  int v2;
  int v3;

  void print() {
    std::cout << v1 << " , " << v2 << " , " << v3 << std::endl;
  }
};

void Base() {
  printf("%s\n", "Base Func");
}

int main() {
  struct Base b;  // 使用时必须添加struct
  b.v1 = 12;
  b.v2 = 13;
  b.v3 = 14;

  b.print();

  Base();
}
```

### `struct 与 class`的区别
`struct`更适合定义数据结构，`class`可以看做对象的实现体；
区别：
* 最基本的区别是默认访问控制，`struct`是`public`, `class`是`private`。

## `union`
节省空间的特殊类，可以有多个数据成员。但任意时刻只能有一个数据成员有值。
当某个成员被赋值后变为未定义状态。

* 默认的访问控制权限为`public`;
* 可以含有构造函数和析构函数；
* 不能含有引用类型；
* 不能继承自其他类，不能作为基类；
* 不能含有虚函数；
* 匿名`union`在定义所在的作用域可以访问`union`成员；
* 匿名`union`不能含有`protected成员或private成员`；
* 全局匿名联合必须是静态的`static`.



