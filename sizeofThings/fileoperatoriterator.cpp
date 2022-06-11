/**
 * @file fileoperatoriterator.cpp
 * @author koritafei (koritafei@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-06-03
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <iterator>
#include <iostream>
#include <set>
#include <algorithm>
#include <fstream>

/**
 * @brief 迭代器操作文件
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc,char** argv){
    std::string from, to;
    std::cin >> from >> to; // 输入文件名

    std::ifstream is {from}; // 对应from文件的输入流
    std::ofstream out {to}; // 对应to文件的输出流

    std::set<std::string> b{std::istream_iterator<std::string>{is}, std::istream_iterator<std::string>{}}; // 读取输入
    std::copy(b.begin(), b.end(), std::ostream_iterator<std::string>{out, "\n"}); // 拷贝到输出

    return !is.eof() || !out;
}

