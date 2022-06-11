/**
 * @file     typeDemo.cpp
 * @brief
 * @author   koritafei
 * @date     2020-6:30 下午
 */

#include <iostream>

using int32 = long;
using int64 = long long;
using uint32 = unsigned long;
using uint64 = unsigned long long;

int64 f() {
    int64 i = 0;
    return i;
}

struct Sales_data{
    std::string bookNo;
    unsigned uints_sold = 0;
    double revenue = 0.0;
};


int main(int argc, char **argv) {
    int32 i = 4000000;
    std::cout << "i = " << i << std::endl;
    decltype(f()) ll = 1234567890;
    std::cout << "ll = " << ll << std::endl;
    decltype((f()))& ii = ll;
    int64& ri = ll;
    std::cout << "&ll = " << &ll << std::endl;
    std::cout << "&ri = " << &ri << std::endl;
    std::cout << "&ii = " << &ii << std::endl;
}

