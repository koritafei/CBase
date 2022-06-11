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
