#include <stdio.h>
#include "myprint.h"

int main () {
  int t;
  stackBot = (void*) &t; // For the relative location
  int a_i = 16;
  int a[a_i]; // New array of size a_i
  for (int i = 0 ; i < a_i ; i++) {
    a[i] = i*3 + 2;  // Put some values in it
  }
  print_array(a_i, a); // Print the array

  printf("Value of a[0]: %d\n", a[0]);

  print_adr("a[0]", &a[0]);
  print_adr("a", &a);

  int* a_ptr = a;
  printf("a_ptr %p", (void*) a_ptr);

  print_adr("a[0]", &a[0]);
  print_adr("a[1]", &a[1]);
  print_adr("a[2]", &a[2]);
  print_adr("a[a_i-1]", &a[a_i-1]);

  print_adr("a", a);
  print_adr("a", a + 1 );

  for (int j = 0; j < (a_i + 2) ; j++) {

    printf("%d\n", *a_ptr);
    a_ptr++;
  }

  printf("Value of a[5]: %d\n", *(a + 5));
}
