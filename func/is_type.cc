/**
 * @file is_type.cc
 * @author koritafei (koritafei@gmail.com)
 * @brief 类型检查函数
 * @version 0.1
 * @date 2020-06-14
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <iostream>
#include <type_traits>

struct TestA {};
class TestB {};
union TestC {
  int i;
  char ch;
};

enum class TestD { Red, Blue, Yellow };

class TestE : public TestB {};

int main(int argc, char **argv) {
  std::cout << std::boolalpha;

  std::cout << "Is Pod " << std::is_pod<int>::value << std::endl;
  std::cout << "内置类型 " << std::is_arithmetic<int>() << std::endl;
  std::cout << "内置类型 " << std::is_arithmetic<std::string>() << std::endl;
  std::cout << "Is Class(struct) " << std::is_class<TestA>::value << std::endl;
  std::cout << "Is Class(class) " << std::is_class<TestB>::value << std::endl;
  std::cout << "Is Base Class(class) " << std::is_base_of<TestB, TestA>::value
            << std::endl;
  std::cout << "Is Base Class(class) " << std::is_base_of<TestE, TestB>::value
            << std::endl;
  std::cout << "Is Base Class(class) " << std::is_base_of<TestB, TestE>::value
            << std::endl;
  std::cout << "Is Object(Object) " << std::is_class<TestB *>::value
            << std::endl;
  std::cout << "Is Class(union) " << std::is_class<TestC>::value << std::endl;
  std::cout << "Is Union(union) " << std::is_union<TestC>::value << std::endl;
  std::cout << "Is Class(enum class) " << std::is_class<TestD>::value
            << std::endl;
  std::cout << "Is Enum(enum class) " << std::is_class<TestD>::value
            << std::endl;

  return 0;
}
