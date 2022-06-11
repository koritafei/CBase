/**
 * @brief        : 
 * @Author       : koritafei
 * @Date         : 2020-05-06 14:17:58 +0800
 * @Email        : koritafei@gmail.com
 * @LastEditors  : koritafei
 * @LastEditTime : 2020-05-08 15:38:15 +0800
 * */


#include <time.h>
#include <iostream>

/**
 * @brief date转string
 * 
 * @param result 
 */
void DatetimeBeforeToString(std::string& result) {
    time_t now;
    time(&now);

    time_t pre = now -  3600 * 24;
    tm *tm_ = localtime(&pre);                // 将time_t格式转换为tm结构体
    result = std::to_string(tm_->tm_year + 1900) + std::to_string(tm_->tm_mon + 1) + std::to_string(tm_->tm_mday);
}



int main(int argc,char **argv){
    static_assert(sizeof(int) >= 4, "interge to big");

    std::string r;
    DatetimeBeforeToString(r);
    std::cout << r << std::endl;
}

