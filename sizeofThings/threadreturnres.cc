/**
 * @file threadreturnres.cc
 * @author koritafei (koritafei@gmail.com)
 * @brief 线程返回结果
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
 * @brief 函数返回结果
 * 
 * @param in 输入数据
 * @param res 输出数据
 */
void f(const std::vector<double>& in, double* res){
    for(auto item : in){
        *res *= item;
    }
}


/**
 * @brief 类实现的函数对象
 * 
 */
class F{
    public:
        /**
         * @brief Construct a new F object
         * 
         * @param in 输入参数
         * @param res 输出参数
         */
        F(const std::vector<double>& in, double* res):_in{in}, _res{res}{}

        void operator()(){
            for(auto item : _in){
                *_res *= item;
            }
        }

    private:
        double* _res;    // 输出结果
        const std::vector<double>& _in; // 输入数组
};


int main(int argc,char** argv){
    std::vector<double> v1{1.2, 2.3, 3.4, 4.5, 5.6};
    std::vector<double> v2{6.7, 7.8, 8.9, 9.0};
    double res1 = 1.0;
    double res2 = 1.0;

    std::cout << "res1 = " << res1 << "\tres2 = " << res2 << std::endl;

    std::thread t1{f, std::ref(v1), &res1}; // f(v1, res1) 一个独立的线程处理, 引用必须使用std::ref()
    std::thread t2{F {std::ref(v2), &res2}}; // F(v2,res2)()独立线程处理, 引用必须使用std::ref()

    t1.join();
    t2.join();

    std::cout << "res1 = " << res1 << "\tres2 = " << res2 << std::endl;
}
