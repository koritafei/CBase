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
