/**
 * @Copyright (c) 2021  koritafei
 * @file stringdemo.cc
 * @brief 
 * @author koritafei (koritafei@gmail.com)
 * @version 0.1
 * @date 2021-04-13 10:04:31
 * 
 * 
 * @par 修改日志:
 * <table>
 * <tr><th>   Date                  <th>  Version    <th>              Author                     <th>   Description
 * <tr><td>  2021-04-13 10:04:31    <td>    1.0      <td>      koritafei(koritafei@gmail.com)     <td>   default,copy,operator= constructor
 * </table>
 * */
#include <iostream>
#include <string>
#include <cstring>


class String {
public:
  String(const char *cstr = 0);
  String(const String &str);
  String &operator=(const String &str);

  virtual ~String();

  char *get_c_str() const {
    return m_data;
  }

private:
  char *m_data;
};

String::String(const char *cstr) {
  if (cstr) {
    m_data = new char[strlen(cstr) + 1];
    strcpy(m_data, cstr);
  } else {
    m_data    = new char[1];
    m_data[0] = '\0';
  }
}

String::~String() {
  delete[] m_data;
}

inline String::String(const String &str) {
  m_data = new char[strlen(str.m_data) + 1];
  strcpy(m_data, str.m_data);
}


inline String &String::operator=(const String &str) {
  if (this == &str) {
    return *this;
  }

  delete []m_data;
  m_data = new char[strlen(str.m_data)+1];
  strcpy(m_data, str.m_data);

  return *this;
}



int main(int argc, char **argv) {
}
