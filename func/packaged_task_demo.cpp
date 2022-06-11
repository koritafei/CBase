/**
 * @file packaged_task_demo.cpp
 * @author koritafei (koritafei@gmail.com)
 * @brief packaged_task封装
 * @version 0.1
 * @date 2020-06-14
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <algorithm>
#include <future>
#include <iostream>
#include <numeric>
#include <thread>
#include <vector>
#include <memory>

class Thread_Task {
public:
  double complate(std::vector<double> &in ) {
    using task_type = double(double *, double *, double); // 函数指针

    std::packaged_task<task_type> prev{accum};  // 打包任务
    std::packaged_task<task_type> last{accum};

    std::future<double> future_prev{prev.get_future()};
    std::future<double> future_last{last.get_future()};

    double* first = &in[0];

    std::thread prev_thread{std::move(prev), first, first + in.size()/2, 0};
    std::thread last_thread{std::move(last), first + in.size()/2, first + in.size(), 0};

    prev_thread.join();
    last_thread.join();

    return future_prev.get() + future_last.get();
  }

private:
  static double accum(double *beg, double *end, double init) {
    return std::accumulate(beg, end, init);
  }
};


int main(int argc,char** argv){
  std::vector<double> in{1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 8.9, 9.0};
  std::unique_ptr<Thread_Task> thread_task_ptr {new Thread_Task()};
  std::cout << thread_task_ptr->complate(in) << std::endl;
}
