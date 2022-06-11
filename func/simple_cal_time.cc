/**
 * @file simple_cal_time.cc
 * @author koritafei (koritafei@gmail.com)
 * @brief 简单计时
 * @version 0.1
 * @date 2020-06-14
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <chrono>
#include <unistd.h>

int main(int argc,char** argv){
  auto begin_time = std::chrono::high_resolution_clock::now();
  sleep(20);
  auto end_time = std::chrono::high_resolution_clock::now();
  std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end_time - begin_time).count() << std::endl;
}
