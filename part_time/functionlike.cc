/**
 * @Copyright (c) 2021  koritafei
 * @file functionlike.cc
 * @brief 仿函数
 * @author koritafei (koritafei@gmail.com)
 * @version 0.1
 * @date 2021-04-16 09:04:94
 *
 *
 * */

#include <iostream>

template <class T>
struct identify {
  const T &operator()(const T &x) {
    return x;
  }
};

template <class Pair>
struct select1st {
  const typename Pair::first_type &operator()(const Pair &x) const {
    return x.first;
  }
};

template <class Pair>
struct select2nd {
  const typename Pair::second_type &operator()(const Pair &x) const {
    return x.second;
  }
};

int main(int argc, char **argv) {
}
