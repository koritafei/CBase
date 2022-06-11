/**
 * @file string.cc
 * @author koritafei (koritafei@gmail.com)
 * @brief string 操作
 * @version 0.1
 * @date 2020-08-31
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <iostream>

std::string char_to_string(char ch) {
  return std::string(1, ch);
}

int main(int argc, char **argv) {
  char *p = "sdfsdfs";
  int   a = 20;
  int * b = &a;
  int * c;
  c = b;
  std::cout << &b << "\t" << *b << std::endl;
  std::cout << &c << "\t" << *c << std::endl;
  std::cout << &p << "\t" << p << std::endl;
  char *q;
  q = p;
  std::cout << &q << "\t" << q << std::endl;
  std::cout << char_to_string('d') << std::endl;
}
