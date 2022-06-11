#include <iostream>

struct A {
  int         a;
  int         b;
  int         c;
  std::string s;
  A() {
  }
  ~A() {
  }
};

struct B {
  std::string s;
  std::string s2;

  B() {
  }
  ~B() {
  }
};

struct C {
  int a;
  int b;

  C() {
  }
  ~C() {
  }
};

union un_a {
  A a;
  B b;
  C c;

  un_a() {
  }

  ~un_a() {
  }
};

int main() {
  A a;
  a.a = 15;
  a.b = 12;
  a.c = 23;
  a.s = "asdasd";

  un_a u;
  u.a = a;

  std::cout << sizeof(u) << std::endl;

  std::cout << u.a.s << std::endl;
}
