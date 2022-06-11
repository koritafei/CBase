/**
 * @file mutexdemo.cc
 * @author koritafei (koritafei@gmail.com)
 * @brief 互斥的实现
 * @version 0.1
 * @date 2020-06-07
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <mutex>
#include <thread>
#include <memory>
#include <unistd.h>

class MudexDemo{
    public:
        void operator()(){
            f();
        }

        void f(){
            std::unique_lock<std::mutex> ulk{_mutex};
            std::cout << "sh = " << sh << std::endl;
            sh += 7;
            std::cout << "sh = " << sh << std::endl;
        }
    private:
        std::mutex _mutex;
        int sh;
};

void thread_run_first(std::shared_ptr<MudexDemo>& mutex){
    while(true){
        std::cout << "first thread " << std::endl;
        mutex->f(); 
        sleep(10);
    }
}

void thread_run_second(std::shared_ptr<MudexDemo>& mutex){
    while(true){
        std::cout << "second thread " << std::endl;
        mutex->f();
        sleep(10);
    }
}


int main(){
    std::shared_ptr<MudexDemo> mudexDemo = std::make_shared<MudexDemo>(); // 智能指针声明方式
    //std::unique_ptr<MudexDemo> mudexDemo {new MudexDemo()};

    std::thread first{thread_run_first, std::ref(mudexDemo)};
    std::thread second{thread_run_second, std::ref(mudexDemo)};

    first.join();
    second.join();
}
