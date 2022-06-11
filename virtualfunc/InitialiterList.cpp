/**
 * @brief        : 
 * @Author       : koritafei
 * @Date         : 2020-04-19 15:37:00 +0800
 * @Email        : koritafei@gmail.com
 * @LastEditors  : koritafei
 * @LastEditTime : 2020-05-09 14:30:19 +0800
 * */

#include <iostream>
#include <initializer_list>

/**
 * @brief ???????
 * 
 * @param ls 
 */
void print(std::initializer_list<std::string> ls) {
    for (auto iter : ls) {
        std::cout << iter << std::endl;
    }
}

int main(int argc, char **argv) {
    std::initializer_list<std::string> t{"qwer", "asdf", "zxcv"};
    print({"dfgh", "sdfsda", "xcvsd"});
    print(t);
    
}

