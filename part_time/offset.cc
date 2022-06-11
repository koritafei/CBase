/**
 * @file offset.cc
 * @author koritafei (koritafei@gmail.com)
 * @brief
 * @version 0.1
 * @date 2021-06-30
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>

#define offset(type, field) ((off_t)(&(((type *)0)->field)))
#define upcast(ptr, type, filed)                                               \
  ((type *)(((char *)(ptr)) - offset(type, filed)))
#define Address(ptr, type, filed)                                              \
  ((type *)(((char *)(ptr)) + offset(type, field)))

struct AB {
  int ad;
};

struct test_a {
  char   a;
  int    b;
  double d;
  AB     ab;
};

int main(int argc, char **argv) {
  test_a t;
  off_t  a = offset(test_a, a);
  std::cout << a << std::endl;
  off_t b = offset(test_a, b);
  std::cout << b << std::endl;
  off_t c = offset(test_a, d);
  std::cout << c << std::endl;
  off_t cc = offset(test_a, ab);
  std::cout << cc << std::endl;
  // char *p1 = upcast(&t, char, a);
  // std::cout << p1 << std::endl;
  // int *p2 = upcast(&t, int, b);
  // std::cout << p2 << std::endl;
  // double *p3 = upcast(&t, double, d);
  // std::cout << p3 << std::endl;
  AB *p4 = upcast(&t, AB, ad);
  std::cout << p4 << std::endl;
  test_a *p5 = Address(p4, test_a, ab);
}