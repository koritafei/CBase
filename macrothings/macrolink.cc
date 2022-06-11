#include <iostream>

#define gc_hello1 "gc_hello1 macro"

#define expA(s) printf("%s\n", gc_##s)
#define expB(s) printf("%s\n", gc_##s)

int main() {
  const char* gc_hello = "I am gc_hello";
  expA(hello1);
  expB(hello);
}
