/**
 * @file threadtransparams.cpp
 * @author koritafei (koritafei@gmail.com)
 * @brief 任务处理数据，数据传递
 * @version 0.1
 * @date 2020-06-04
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <thread>
#include <vector>

/**
 * @brief 函数传入参数
 * 
 * @param v 输入数据
 */
void f(const std::vector<double>& v) {
    for(auto item : v){
        std::cout << item << "\t";
    }
    std::cout << std::endl;
}

/**
 * @brief 函数对象，传递参数
 * 
 */
struct F{
    F(std::vector<double>& v):_v{v}{}

    void operator()() const {
        for(auto item : _v){
            std::cout << item << "\t";
        }
        std::cout << std::endl;
    }

    std::vector<double>& _v;
};

int main(int argc,char** argv){
    std::vector<double> v1{1.2, 2.3, 3.4, 4.5, 5.6};
    std::vector<double> v2{6.7, 7.8, 8.9, 9.0};

    std::thread t1{f, std::ref(v1)}; // f(v1) 一个独立的线程处理, 引用必须使用std::ref()
    std::thread t2{F {std::ref(v2)}}; // F(v2)()独立线程处理, 引用必须使用std::ref()

    t1.join();
    t2.join();
}
