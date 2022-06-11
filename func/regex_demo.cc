/**
 * @file regex_demo.cc
 * @author koritafei (koritafei@gmail.com)
 * @brief 正则表达式
 * @version 0.1
 * @date 2020-06-14
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <regex>

int main(int argc,char** argv){

  std::regex pat {"\\d{4}-\\d{2}-\\d{2}"};
  int lineno;
  for (std::string line; getline(std::cin, line);) {
    ++lineno;
    std::smatch matches;
    if(std::regex_search(line, matches, pat)){
      std::cout << lineno << " : " << matches[0] << "\n";
    }
  }

}
