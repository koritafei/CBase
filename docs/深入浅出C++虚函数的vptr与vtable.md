## 基础理论
为实现虚函数，`c++`使用了一种称为虚拟表的特殊后期绑定形式。
该虚拟表主要用于解决在动态/后期绑定形式的函数调用函数的查找表。

> **每个使用虚函数的类(或者从使用虚函数的类派生的类)都有自己的虚函数表；**
> 该表只是编译器在编译时期设置的静态数组；
> 虚拟表包含可由类的对象调用的每个虚函数的一个条目；
> 该表的每个条目只是一个虚函数指针，指向该类可访问的派生函数。

> 编译器添加一个隐藏指向基类的指针，我们称之为`vptr`.
> `vptr`在创建类实例时自动设置，以便指向该类的虚拟表；
> **vptr由派生类继承。**

### 实现与内部结构
![vtable](./images/vtable.jpeg)

```cpp
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
```
虚函数的查找过程：
1. 程序识别出`fun1()`是个虚函数;
2. 使用`pt->vptr`来获取`Derived`的虚拟表;
3. 查找`Derived`虚拟表中调用哪个版本的`fun1()`。
4. 发现调用的是`Derived::fun1()`。因此`pt->fun1()`被解析为`Derived::fun1()`!

静态函数能够声明为虚函数？
* 静态函数不可以声明为虚函数，同时也不可以被`const和voatile`修饰；
* `static`成员函数不属于任何类对象或类实例，所以即使给此函数加上`virutal`也是没有任何意义
* 虚函数依靠`vptr和vtable`来处理。`vptr`是一个指针，在类的构造函数中创建生成，并且只能用`this`指针来访问它，静态成员函数没有`this`指针，所以无法访问`vptr`。

构造函数可以是虚函数么？
* 构造函数不可以声明为虚函数。同时除了`inline|explicit`之外，构造函数不允许使用其它任何关键字。
* 虚函数表`vtable`是在编译阶段就已经建立的，但指向虚函数表的指针`vptr`是在运行阶段实例化对象时才产生的。 
* 如果类含有虚函数，编译器会在构造函数中添加代码来创建`vptr`。 
* 如果构造函数是虚的，那么它需要`vptr`来访问`vtable`，可这个时候`vptr`还没产生。 
* 因此，构造函数不可以为虚函数。


使用虚函数，是需要在信息不全的情况下进行多态运行。
而构造函数是用来初始化实例的，实例的类型必须是明确的。 
因此，构造函数没有必要被声明为虚函数。

析构函数可以是虚函数么？
* 析构函数可以声明为虚函数。
* 如果需要删除一个指向派生类的基类指针时，应该把析构函数声明为虚函数。
* 只要一个类有可能会被其它类所继承， 就应该声明虚析构函数(哪怕该析构函数不执行任何操作)。

虚函数可以是私有函数么？
* 基类指针指向继承类对象，则调用继承类对象的函数；
* `int main()`必须声明为`Base`类的友元，否则编译失败。 
* 编译器报错： `ptr`无法访问私有函数。 
* 基类声明为`public`， 继承类为`private`，该问题就不存在了。

```cpp
#include <iostream>

class A {
private:
  virtual void func() {
    std::cout << "func" << std::endl;
  }

  friend int main(); // 不存在时，报错，无法调用私有函数
}; 

int main() {
  A a;
  a.func();
}

```

虚函数可以被内联么？
* 通常类成员函数都会被编译器考虑是否进行内联。 
* 但通过基类指针或者引用调用的虚函数必定不能被内联。 
* 实体对象调用虚函数或者静态调用时可以被内联，虚析构函数的静态调用也一定会被内联展开。
* 虚函数可以是内联函数，内联是可以修饰虚函数的，但是当虚函数表现多态性的时候不能内联。
* 内联是在编译器建议编译器内联，而虚函数的多态性在运行期，编译器无法知道运行期调用哪个代码，因此虚函数表现为多态性时（运行期）不可以内联。
* `inline virtual `唯一可以内联的时候是：编译器知道所调用的对象是哪个类（如 ·），这只有在编译器具有实际对象而不是对象的指针或引用时才会发生。



