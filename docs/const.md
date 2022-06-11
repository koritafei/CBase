## `const`含义
常类型是指使用类型修饰符`const`说明的类型，常类型的变量或值是不能被更新的。

### `const`的作用
* 可以定义常量
 ```cpp
  const int a = 100;
 ``` 
* 类型检查
  > `const与#define`的区别：
  > **const具有类型编译器可以进行安全检查，#define定义没有数据类型，只是简单的字符串替换，不能进行安全检查。**
  > `const`定义的常量只有类型为整型或枚举，且以常量表达式初始化时才能作为常量表达式；
  > 其余情况下只是`const`限定的变量，不可与常量混淆。

* 防止修改，起保护作用，增加程序健壮性。
* 节省空间避免不必要的内存分配
  * `const`常量从汇编的角度来看，只是给出了内存地址；不像`#define`那样直接给出立即数；
  * `const`常量在运行时只有一份拷贝，`#define`存在若干个拷贝。

* `const`对象默认为文件局部对象
  * 非`const`变量默认为`extern`,`const`变量其他文件可以访问，需要使用`extern`显示指明。

* 定义常量
  * `const int a = 10;` 变量值不可修改
  * `const int i;` 变量必须初始化

* 指针与`const`
  * 与指针相对应的`const`有四种：
  ```cpp
  const char *a; // 指向const对象的指针，或指向常量的指针
  char const *a; // 同上
  char *const a; // 指向类型对象的const指针，常指针，const指针
  const char * const a; // 指向const对象的const指针
  ```
  > **如果`const`位于`*`的左侧，则`const`就是用来修饰指针所指向的变量，即指针指向为常量；**
  > **如果`const`位于`*`的右侧，`const`就是修饰指针本身，即指针自身为常量。**
  具体使用：
  1.  指向指针的常量
   ```cpp
    const int *p;
    *p = 10; // error
   ```
   指向指针的常量，不可修改常量内容。
   不可使用`void *`保存const对象地址，必须使用`const void *`类型。
   **可以将非`const`的对象的地址，赋值给`const`对象的指针。**
   > 总结：
   > 1. 对于指向常量的指针，不能通过指针来修改对象的值；
   > 2. 不可使用`void *`保存const对象地址，必须使用`const void *`类型;
   > 3. 允许把非`const`对象的地址赋值给`const`对象的指针，如果要修改指针所指向的对象值，必须通过其他方式修改，不能直接通过当前指针直接修改.

  2. 常指针
   `const`必须进行初始化，且`const`指针的值不能修改。
   ```cpp
    #include <iostream>

    const int a = 100;

    int main() {
      int        num = 0;
      int *const ptr = &num;  // 必须进行初始化，且const指针的值不可修改
      int       *t = &num;
      *t           = 10;
      *ptr         = 20;  // 允许修改指针指向的值
      int num2     = 0;
      // ptr          = &num2;  // error! 不允许修改指针指向的对象
      std::cout << *ptr << std::endl;
    }
   ```
   当把`const`常量的地址赋值给非`const`的指针时报错。

* 函数中使用`const`
  * `const`修饰参数：
  1. 对非内部数据类型的输入参数，应该将值传递改为`const`引用传递；
  2. 对内部类型的输入参数，无需将值传递改为`const`引用传递。

* 类中使用`const`
  * 在类中任何不会修改数据成员的函数都应该声明为`const`类型。
  * 使用`const`修饰的成员函数称为常成员函数，只有常成员函数有资格操作常量或常对象。
  * 类中的`const`成员变量必须通过初始化列表进行初始化。
  * `const`对象只能访问`const`成员函数，非`const`对象可以访问任意函数，包括`const`成员函数。



