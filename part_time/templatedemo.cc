/**
 * @Copyright (c) 2021  koritafei
 * @file templatedemo.cc
 * @brief 模板偏特化
 * @author koritafei (koritafei@gmail.com)
 * @version 0.1
 * @date 2021-04-16 10:04:45
 * 
 * 
 * */

#include <iostream>

template <class T>
struct hash{};

template <>
struct hash<char> {
  size_t operator()(char x) const {
    return x;
  }
};

template <>
struct hash<int>{
  size_t operator()(int x) const {
    return x;
  }
};

template <>
struct hash<long> {
  size_t operator()(long x) const {
    return x;
  }
};

// template <typename... Types>
// void print(const Types&... d) {
//   print(d...);
// }

// template<>
// void print() {
//   std::cout << "Empty" << std::endl;
// }

// template <typename T, typename... Types>
// void print(const T &firstArg, const Types&... args){
//   std::cout << firstArg << std::endl;
//   print<Types...>(args...);
// }

void print() {
  std::cout << "Empty" << std::endl;
}

template <typename T, typename... Types>
void print(const T &firstArg, const Types&... args){
  std::cout << firstArg << std::endl;
  print(args...);
}

int main(int argc, char **argv) {
  std::cout << hash<long>()(1000) << std::endl;
  print(1,2,3,4,5);
}
