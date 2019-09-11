#include <stdio.h>

// This contains some some to print the memory in a nice way
#include "myprint.h"

int main () {
  // Lets
  int t = 6; 
  stackBot = &t; // This is also used for the address printing.
  int x = t;
  char c = 'c';
  char v = 'v';
  double d = 1.3;
  char b = 'b';
  // OK, now we have loads of different values

  char* c_ptr = &c;
  int*  x_ptr = &x;
  // Great, we also have pointers

  // So what are their addresses?
  print_adr(" t", (void *) &t);
  print_adr(" x", (void *) &x);
  print_adr(" c", (void *) &c);
  print_adr(" v", (void *) &v);
  print_adr(" d", (void *) &d);
  print_adr(" b", (void *) &b);
  print_adr(" c_ptr", (void *) &c_ptr);
  print_adr(" x_ptr", (void *) &x_ptr);

  // Well c_ptr is a pointer, so we can see what is points at
  print_adr(" c", (void *) c_ptr);
  // What happens if we subtract one from it?
  print_adr(" c-1", (void *) (c_ptr - 1) );
  // Ahh, we get the next defined variable which is b

  // This come down to the implementation of the program stack. 
  // By convention it grows downwards, which is why we use subtraction
  // (Look at the slides for a quick picture the program stack.. 
  // .. we will come back to this in details later in the course.)

  printf("Value of v: %c\n", *(c_ptr - 1));
  // So we actually get the character we put in c

  // OK, lets try the same for int pointer
  print_adr(" x-1", (void *) (x_ptr - 1) );
  // This jumps 4 bytes. 
  // So length value that is used when doing pointer arithmetic is
  //  dependent on the size of the type of the pointer. 

  // Lets look at arrays.
}