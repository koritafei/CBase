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
