/**
 * @file multimetux.cc
 * @author koritafei (koritafei@gmail.com)
 * @brief 获取多个锁，防止死锁
 * @version 0.1
 * @date 2020-06-08
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <thread>
#include <mutex>
#include <memory>
#include <unistd.h>

class MultiMutex{
    public:
        void MultiLock(){
            std::unique_lock<std::mutex> _unique_lock_first{_mutex_first, std::defer_lock}; // 延迟加锁
            std::unique_lock<std::mutex> _unique_lock_second{_mutex_second, std::defer_lock};
            std::unique_lock<std::mutex> _unique_lock_thrid{_mutex_thrid, std::defer_lock};

            std::cout << "i = " << i << std::endl;
            std::lock(_unique_lock_first, _unique_lock_second, _unique_lock_thrid); // 一次获取所有锁
            i += 20;
            std::cout << "i = " << i << std::endl; // 锁自动释放
        }
    private:
        std::mutex _mutex_first;
        std::mutex _mutex_second;
        std::mutex _mutex_thrid;
        int i;
};

void thread_first_run(std::unique_ptr<MultiMutex>& _multiMutex){
    while(true) {
         std::cout << "first \n" ;
        _multiMutex->MultiLock();
        sleep(5);
    }
}

void thread_second_run(std::unique_ptr<MultiMutex>& _multiMutex){
    while(true) {
        std::cout << "second \n" ;
        _multiMutex->MultiLock();
        sleep(5);
    }
}

int main(int argc,char** argv){
    std::unique_ptr<MultiMutex> multiMutex{new MultiMutex()};
    std::thread t1{thread_first_run, std::ref(multiMutex)};
    std::thread t2{thread_second_run, std::ref(multiMutex)};

    t1.join();
    t2.join();
}
