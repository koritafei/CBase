/**
 * @file enumclass.cc
 * @author koritafei (koritafei@gmail.com)
 * @brief enum类型
 * @version 0.1
 * @date 2020-06-23
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <iostream>

enum class color { red, green, yellow };

enum Color { red, green, yellow };

int main(int argc, char** argv) {
  color c = color::red;
  if (c == color::red) {
    std::cout << "Red" << std::endl;
  }
  std::cout << Color::red << std::endl;
}
