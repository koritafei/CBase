/**
 * @file productandcustom.cc
 * @author koritafei (koritafei@gmail.com)
 * @brief 多生产者多消费者模型
 * @version 0.1
 * @date 2020-06-09
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include <condition_variable>
#include <sstream>
#include <memory>
#include <chrono>
#include <vector>
#include <unistd.h>

// 通信对象, 线程之间的消息体
class Message{
    public:

        void put(const std::thread::id& id) {
            this->_msg = " message from thread " + threadIDTostring(id) ;
        }

        std::string get(){
            return this->_msg;
        }
    private:

        std::string threadIDTostring(const std::thread::id& id) {
            std::stringstream sin;
            sin << id;
            return sin.str();
        } 

        std::string _msg;
};

class ProductAndCustom{
    public:

        ProductAndCustom():_ready(false){
        }

        void customer(){
            while(true){
                {   // 锁的作用域
                    std::unique_lock<std::mutex> ulk{_mutex};
                    _conn.wait(ulk,[&]{return _ready;});
                    auto message = _queue.front();
                    _queue.pop();
                    _ready = false;  // 消费后，_ready置为false，防止其他消费者在生产者未放置数据时获得锁，造成段错误
                    std::cout << "The custom thread " << std::this_thread::get_id() << " custom " << message->get() << std::endl;
                }
                sleep(1);
            }
        }

        void product(){
            while(true){
                std::shared_ptr<Message> message = std::make_shared<Message>();
                message->put(std::this_thread::get_id());
                {
                    std::unique_lock<std::mutex> ulk{_mutex};
                    _queue.push(message);
                    _ready = true;
                }
                _conn.notify_all();
                sleep(1);
            }
        }

    private:
        std::condition_variable _conn;
        std::queue<std::shared_ptr<Message>> _queue;
        std::mutex _mutex;
        bool _ready;
};

int main(int argc,char** argv){
    const int count = 100;

    std::shared_ptr<ProductAndCustom> productAndCustom = std::make_shared<ProductAndCustom>();

    std::vector<std::thread> product;
    for (size_t i = 0; i < count; i++){
        product.push_back(std::thread{&ProductAndCustom::product, productAndCustom});
    }


    std::vector<std::thread> customer;
    for (size_t i = 0; i < count; i++){
        customer.push_back(std::thread{&ProductAndCustom::customer, productAndCustom});
    }
    
    std::for_each(product.begin(), product.end(), std::mem_fn(&std::thread::join));
    std::for_each(customer.begin(), customer.end(), std::mem_fn(&std::thread::join));
}
