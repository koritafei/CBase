/**
 * @file threadtask.cpp
 * @author koritafei (koritafei@gmail.com)
 * @brief 线程与任务
 * @version 0.1
 * @date 2020-06-04
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <thread>

// 函数
void f(){
    std::cout << "Function" << std::endl;
}

// 函数对象
struct F {
    void operator()(){
        std::cout << "Functor Object " << std::endl;
    }
};

void user(){
    std::thread t1{f};
    std::thread t2{F()};

    t1.join();  // 等待线程结束
    t2.join();  // 等待线程结束
}


int main(int argc,char** argv){
    user();
}
