/**
 * @file     whiledemo.cpp
 * @brief   
 * @author   koritafei
 * @date     2020-10:28 上午
 */

#include <iostream>

int main(int argc,char **argv){
    int val1 = 0;
    int sum = 0;
    while (std::cin>>val1){
        sum += val1;
    }
    std::cout<<"sum = "<<sum<<std::endl;
}

