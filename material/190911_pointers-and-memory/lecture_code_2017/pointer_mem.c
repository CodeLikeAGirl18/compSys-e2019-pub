#include <stdio.h>
#include "myprint.h"

int main () {
  int t = 6;
  stackBot = &t;
  int x = t;
  char c = 'c';
  char v = 'v';
  double d = 1.3;
  char b = 'b';

  char* c_ptr = &c;
  int*  x_ptr = &x;

  print_adr(" t", (void *) &t);
  print_adr(" x", (void *) &x);
  print_adr(" c", (void *) &c);
  print_adr(" v", (void *) &v);
  print_adr(" d", (void *) &d);
  print_adr(" b", (void *) &b);
  print_adr(" c_ptr", (void *) &c_ptr);
  print_adr(" x_ptr", (void *) &x_ptr);

  print_adr(" c", (void *) c_ptr);
  print_adr(" c-1", (void *) (c_ptr - 1) );

  printf("Value of v: %c\n", *(c_ptr - 1));

  print_adr(" x-1", (void *) (x_ptr - 1) );


}