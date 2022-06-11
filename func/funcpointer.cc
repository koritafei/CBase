#include <iostream>

/**
 * @brief 定义函数指针，返回值为void，参数为int
 * */
void (*func)(int);

/**
 * @brief 代表一种新类型，不是变量！所以与上述的pFun不一样！
 * */
typedef void (*pfunc)(void);

void fun() {
  std::cout << "ad" << std::endl;
}

void glFunc(int a) {
  std::cout << a << std::endl;
}

int main() {
  pfunc f = fun;
  f();
  func = glFunc;
  (*func)(2);
}