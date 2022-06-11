/**
 * @Copyright (c) 2021  koritafei
 * @file conversion.cc
 * @brief 转换函数
 * @author koritafei (koritafei@gmail.com)
 * @version 0.1
 * @date 2021-04-15 20:04:85
 *
 *
 * */

#include <iostream>

class Fraction {
public:
  Fraction(int num, int den = 1) : m_numberation(num), m_denominator(den) {
  }

  operator double() const {
    return (double)(m_numberation / m_denominator);
  }

private:
  int m_numberation;  // 分子
  int m_denominator;  // 分母
};

int main(int argc, char **argv) {
  Fraction f(3,5);
  double d = 4 + f; // 调用operator double() 将f转为double
  std::cout << d << std::endl;
}
