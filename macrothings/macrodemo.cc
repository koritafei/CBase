#include <cstdio>
#include <iostream>
#include <string>

#define exp(s)  printf("test s is %s\n", s)
#define exp1(s) printf("test s is %s\n", s)
#define exp2(s) #s

int main() {
  exp("hello");
  exp1("hello");

  std::string str = exp2(bac);

  std::cout << str.size() << ' ' << str << std::endl;

  // 忽略传入参数前后的空格
  std::string str1 = exp2(bac adas);
  std::cout << str1.size() << ' ' << str1 << std::endl;
}
