/**
 * @file pair_and_tuple.cc
 * @author koritafei (koritafei@gmail.com)
 * @brief pair和tuple类型测试
 * @version 0.1
 * @date 2020-06-14
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <iostream>
#include <thread>
#include <tuple>
#include <utility>

std::pair<int, int> make_pair(int &first, int &second) {
  return std::make_pair(first, second);
}

std::tuple<int, double, std::string> make_tuple(int &first, double &second,
                                                std::string &third) {
  return std::make_tuple(first, second, third);
}

int main(int argc, char **argv) {
  int first = 12;
  int second = 34;
  auto pair_p = make_pair(first, second);
  std::cout << "First is " << pair_p.first << "\t second is " << pair_p.second
            << std::endl;
  double second_d = 35.89;
  std::string third = "Hello Tuple!";
  auto tuple = make_tuple(first, second_d, third);
  std::cout << "Tuple first is " << std::get<0>(tuple) << "\tTuple second is "
            << std::get<1>(tuple) << "\tTuple third is " << std::get<2>(tuple)
            << std::endl;
}
