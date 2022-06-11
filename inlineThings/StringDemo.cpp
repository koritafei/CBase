/**
 * @brief        : 
 * @Author       : koritafei
 * @Date         : 2020-04-11 17:06:49 +0800
 * @Email        : koritafei@gmail.com
 * @LastEditors: koritafei
 * @LastEditTime: 2020-04-12 10:42:40 +0800
 * @FilePath     : /C++Base/Chapter03/StringDemo.cpp
 * */

#include <iostream>
#include <string>
#include <typeinfo>

int main(int argc,char** argv){
    std::string str = "sdflsdjflskjdfl";
    auto len = str.size();
    std::cout << len << std::endl;
    std::cout << typeid(len).name() << std::endl;
    
    return 0;
}

