#include <iostream>
#include <string>

int main() {
  std::string s    = "sfsdfs";
  std::string a    = "sdfsfdsdfadsa";
  bool        flag = false;
  if (s.size() >= 0 && !flag) {
    std::cout << s << std::endl;
    flag = true;
  }
  if (a.size() >= 0 && !flag) {
    std::cout << a << std::endl;
  }
}
