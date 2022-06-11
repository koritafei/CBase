/**
 * @brief 获取当前日期
 */
#include <iostream>
#include <string>
using namespace std;

static string getCurrentTimeStr() {
  time_t t = time(NULL);
  char ch[64] = {0};
  strftime(ch, sizeof(ch) - 1, "%Y%m%d",
           localtime(&t)); //年月日
  return ch;
}

int main() {
  cout << getCurrentTimeStr() << endl;
  return 0;
}