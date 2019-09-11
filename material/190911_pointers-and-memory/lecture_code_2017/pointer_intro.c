#include <stdio.h>

int main () {
  int x;
  printf("Address of x: %p\n", (void *) &x);

  x = 5;
  printf("Value of x: %d\n", x);

  int* x_ptr;
  printf("Address of x_ptr: %p\n", (void *) &x_ptr);

  x_ptr = &x;
  printf("Address of x: %p\n", (void *) x_ptr);

  *x_ptr = 42;
  printf("Value of x_ptr: %d\n", *x_ptr);
  printf("Value of x: %d\n", x);

  int* z_ptr;
  z_ptr = x_ptr;
  printf("Address of x: %p\n", (void *) z_ptr);

  *z_ptr += 3;
  printf("Value of x: %d\n", x);
  printf("Address of x: %p\n", (void *) z_ptr);

  // *(z_ptr++);
  printf("Value of z_ptr: %p\n", z_ptr);
  printf("Value of z_ptr: %p\n", (++z_ptr));

  (*z_ptr)++;
  printf("Value of x: %d\n", x);

  --(*z_ptr);
  printf("Value of x: %d\n", x);

  int** x_pptr;
  x_pptr = &x_ptr;
  printf("Value of x: %d\n", **x_pptr);

}