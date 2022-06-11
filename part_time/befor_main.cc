#include <stdio.h>

__attribute((constructor)) void beforMain() {
  printf( "Before Main\n");
}

int main(int argc, char **argv) {
  printf("main function\n");
}
