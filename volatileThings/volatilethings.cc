#include <iostream>

static int i = 0;

void dosomething() {
  std::cout << "do some things" << std::endl;
}

int main() {
  while (1) {
    if (i) dosomething();
  }
}

/* Interrupt service routine */
void IRS() {
  i = 1;
}