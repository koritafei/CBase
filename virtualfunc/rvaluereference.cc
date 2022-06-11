/**
 * @file rvaluereference.cc
 * @author koritafei (koritafei@gmail.com)
 * @brief 右值引用
 * @version 0.1
 * @date 2020-06-16
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <algorithm>
#include <iostream>
#include <vector>

int main(int argc, char **argv) {
  int &&val = 10;
  std::cout << val << std::endl;
}
