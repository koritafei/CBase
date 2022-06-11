/**
 * @file char_pointer.cc
 * @author koritafei (koritafei@gmail.com)
 * @brief char *操作
 * @version 0.1
 * @date 2020-09-08
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <iostream>

int main(int argc, char **argv) {
  char *p = "sdfsdf";
  char *q = new char[2];
  q[1] = 's', q[0] = 'd';
  std::cout << p << "\t" << q << std::endl;
  char *oq = q;
  std::cout << oq << "\t" << &oq << "\t" << q << "\t" << &q << std::endl;
  // delete[] q;
  q = new char[4];
  std::cout << oq << "\t" << &oq << std::endl;
  std::cout << oq << "\t" << &oq << "\t" << q << "\t" << &q << std::endl;

  delete[] oq;
  delete[] q;
}
