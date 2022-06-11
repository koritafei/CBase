#include <iostream>

class A {
public:
  A(int a) : a(a) {
  }

  ~A() {
  }

  friend class B;
  friend void print(A &a);

private:
  int a;
};

class B {
public:
  B() {
  }

  ~B() {
  }

  void print(A &a) {
    std::cout << a.a << std::endl;
  }
};

void print(A &a) {
  std::cout << a.a << std::endl;
}

int main() {
  A a{10};

  print(a);
  B b;
  b.print(a);
}