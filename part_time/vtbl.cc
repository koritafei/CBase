/**
 * @Copyright (c) 2021  koritafei
 * @file vtbl.cc
 * @brief
 * @author koritafei (koritafei@gmail.com)
 * @version 0.1
 * @date 2021-04-16 15:04:41
 *
 * */

#include <iostream>

class A {
public:
  virtual void vfunc1() {
  }
  virtual void vfunc2() {
  }

  void func1() {
  }
  void func2() {
  }

private:
  int m_data1, m_data2;
};

class B : public A {
public:
  virtual void vfunc2() {
  }

  void func2() {
  }

private:
  int m_data3;
};

class C : public A {
public:
  virtual void vfunc1() {
  }

  void func1() {
  }

private:
  int m_data1;
  int m_data4;
};

int main(int argc, char **argv){
  
}
