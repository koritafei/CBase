/**
 * @file futureandpromise.cc
 * @author koritafei (koritafei@gmail.com)
 * @brief future与promise封装多线程通信
 * @version 0.1
 * @date 2020-06-13
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <exception>
#include <future>
#include <iostream>
#include <list>
#include <memory>
#include <sstream>
#include <thread>
#include <unistd.h>
#include <vector>

/**
 * @brief 多线程通信消息体
 *
 */
class Message {
public:
  void put(const std::thread::id &id) {
    this->_msg = " , message from thread " + thread_id_to_string(id);
  }

  std::string get() { return this->_msg; }

private:
  std::string thread_id_to_string(const std::thread::id &id) {
    std::stringstream out;
    out << id;
    return out.str();
  }

  std::string _msg;
};

using message_shared_ptr = std::shared_ptr<Message>;

template <class T> class FutureAndCustomer {
public:
  using promise = std::promise<T>;
  using future = std::future<T>;

  void get(future &future_element) {
    try {
      auto message = future_element.get();
      std::cout << "Message is custom by thread " << std::this_thread::get_id()
                << message->get() << std::endl;
    } catch (std::future_error &e) {
      std::cout << "Exception " << e.what() << std::endl;
    }
  }

  void set(promise &promise_element, message_shared_ptr &message_ptr) {
    try {
      message_ptr->put(std::this_thread::get_id());
      promise_element.set_value(message_ptr);
    } catch (...) {
      promise_element.set_exception(std::current_exception());
    }
  }
};

void create_thread_promise_future(
    std::vector<std::thread> &product_threads,
    std::vector<std::thread> &custom_threads,
    std::shared_ptr<FutureAndCustomer<message_shared_ptr>>
        &futureAndCustomer_ptr) {
  message_shared_ptr _message_shared_ptr = std::make_shared<Message>();
  std::promise<message_shared_ptr> promise_element;
  auto future_element = promise_element.get_future();

  product_threads.push_back(std::thread{
      &FutureAndCustomer<message_shared_ptr>::set, futureAndCustomer_ptr,
      std::ref(promise_element), std::ref(_message_shared_ptr)});

  custom_threads.push_back(
      std::thread{&FutureAndCustomer<message_shared_ptr>::get,
                  futureAndCustomer_ptr, std::ref(future_element)});
}

int main(int argc, char **argv) {
  const size_t thread_count = 1; // 线程数目
  std::vector<std::thread> product_threads;
  std::vector<std::thread> custom_threads;

  std::cout << "Main thread id is " << std::this_thread::get_id() << std::endl;
  std::shared_ptr<FutureAndCustomer<message_shared_ptr>> futureAndCustomer_ptr{
      new FutureAndCustomer<message_shared_ptr>()};
   for (size_t i = 0; i < thread_count; i++) {
       create_thread_promise_future(product_threads, custom_threads, futureAndCustomer_ptr);
  }

  std::for_each(product_threads.begin(), product_threads.end(),
                std::mem_fn(&std::thread::join));
  std::for_each(custom_threads.begin(), custom_threads.end(),
                std::mem_fn(&std::thread::join));
}
