#include <stdio.h>

void min_funk(int *x) {
  *x += 3;
}

int main() {

  int min_x = 7;

  printf("%d\n", min_x);

  min_funk(&min_x);

  printf("%d\n", min_x);
}
