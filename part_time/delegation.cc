/**
 * @Copyright (c) 2021  koritafei
 * @file delegation.cc
 * @brief delegation 实现
 * @author koritafei (koritafei@gmail.com)
 * @version 0.1
 * @date 2021-04-15 16:04:14
 *
 * */

#include <functional>
#include <iostream>
#include <string>
#include <vector>
#include <functional>

class IObj {
public:
  virtual int callback(std::string t_data) = 0;
};

class AppleObj : public virtual IObj {
public:
  int callback(std::string t_data) final {
    std::cout << "This is apple obj! Get " <<t_data<< std::endl;
    return 0;
  }
};

class AndroidObj : public virtual IObj {
public:
  int callback(std::string t_data) final {
    std::cout << "This is android obj! Get " << t_data << std::endl;
    return 0;
  }
};

class DeleManger {
public:
  DeleManger() {
  }
  ~DeleManger() {
  }

  void addObj(std::function<int(std::string)> t_dele){
    __dele_list.push_back(t_dele);
  }

  void nofity(std::string t_msg) {
    if (__dele_list.empty()) {
      std::cout << "List is empty" << std::endl;
      return;
    }

    for (auto iter : __dele_list) {
      iter(t_msg);
    }
  }

private:
  std::vector<std::function<int(std::string)>> __dele_list;
};


int main(int argc,char **argv) {
  DeleManger i_delemanger;
  AppleObj apple;
  AndroidObj android;

  using std::placeholders::_1;
  std::function<int(std::string)> i_dele_apple = std::bind(&AppleObj::callback, apple, _1);
  i_delemanger.addObj(i_dele_apple);
  std::function<int(std::string)> i_dele_android = std::bind(&AndroidObj::callback, android, _1);
  i_delemanger.addObj(i_dele_android);

  i_delemanger.nofity("Moile Obj");
}