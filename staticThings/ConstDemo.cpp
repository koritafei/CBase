/**
 * @file     ConstDemo.cpp
 * @brief   
 * @author   koritafei
 * @date     2020-5:36 下午
 */



#include <iostream>

constexpr double square(double x){
    return x * x;
}

int main(int argc, char **argv) {
    int i = 20;
    const int a = i; // 底层const，其值不可改变
    // a = 30; // error
    int *const pi = &i; // 顶层const，指向的值可以修改，但是指向的对象补课修改
    // pi = &a;  error
    std::cout << "i = " << i << std::endl;
    *pi = 30;
    std::cout << "i = " << i << std::endl;
    const int *const pInt = &i;  // 靠右为顶层const，指向对象不可改变；靠左为底层const，其值不可改变
    // 不可修改其值
    // pInt = 40;
    std::cout << *pInt << std::endl;
    // 常量表达式
    constexpr int t = 50;
    constexpr int tt = t * t;
    std::cout << t << "\t" << tt << std::endl;
    using name = int;
    name n = 50;
    std::cout << n << std::endl;
    const double cd = 20.0;
    std::cout << square(cd) << std::endl;
    double dd = 10.0;
    std::cout << square(dd) << std::endl;
}
