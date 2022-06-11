/**
 * @file smartpointer.cpp
 * @author koritafei (koritafei@gmail.com)
 * @brief 智能指针
 * @version 0.1
 * @date 2020-06-03
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <memory>
#include <iostream>
#include <iterator>

int main(int argc,char** argv){
    std::unique_ptr<int> uqeptr_t{new int};
    *uqeptr_t = 100;
    std::cout << "uqeptr_t = " << uqeptr_t  << "\t*uqeptr_t = " << *uqeptr_t << std::endl;
    std::unique_ptr<int> p = std::move(uqeptr_t); // 不支持赋值构造，只能支持移动构造语义
    std::cout << "p = " << p << "\t*p = "<< *p << std::endl;
    std::shared_ptr<int> shared{new int};
    *shared = 30;
    std::cout << "shared = "<< shared << "\t*shared = " << *shared << std::endl;
    std::shared_ptr<int> shared2{shared}; // 支持赋值构造
    std::cout << "shared2 = "<< shared2 << "\t*shared2 = " << *shared2 << "\tshared = "<< shared << "\t*shared = " << *shared << std::endl;
    std::shared_ptr<int> shared3 = std::move(shared); // 支持移动构造,shared,shared2释放
    std::cout << "shared3 = "<< shared3 << "\t*shared3 = " << *shared3 << std::endl;
    std::cout << "shared2 = "<< shared2 << "\t*shared2 = " << *shared2 << "\tshared = "<< shared << "\t*shared = " << *shared << std::endl; // 指针已释放，段错误
}

