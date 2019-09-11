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

  // int* a_ptr = &a;  // This is wrong as a is not an integer

  printf("Value of a[0]: %d\n", a[0]);
  //printf("Value of *a  : %d\n", a);
  printf("Value of *a: %d\n", *a);

  int* a_ptr = a; // So a (an integer array) is a pointer to an integer
  printf("Value of *a_ptr: %d\n", *a_ptr);  // They do have the same location

  // So where are they located in my relative memory
  print_adr("&a[0] ", &(a[0])); 
  print_adr("&a[1] ", &(a[1]));
  print_adr("&a[2] ", &(a[2]));
  print_adr("&a[15]", &(a[15]));

  // So can we 
  print_adr("a     ", a);
  print_adr("a + 1 ", a+1); 
  // The compiler uses the size of the pointee to know how much to jump
  // For me (64 bit machine) the size of int is 32 bit, thus it adds 4 bytes

  printf("Value of *(a+1): %d\n", *(a + 1)); // We can also get the values by dereferencing

  // Array notation is just syntactic sugar for pointer arithmetic
  if (a[2] == *(a + 2)) {
    printf("Hurray, They are equal: a[2] == *(a + 2)\n");
  }
  else {
    printf("I failed\n");
  }
  // This is why arrays are indexed from 0 and they are placed in the opposite direction on the stack

  // Lets make a 2-dimensional array
  int b_i = 4;
  int b_j = 8;
  int b[b_i][b_j];

  // Nested loop for assigning some variables
  for (int i = 0 ; i < b_i ; i++) {
    for (int j = 0 ; j < b_j ; j++) {
      b[i][j] = i*3 + j + 2;
    }  
  }
  print_2Darray(b_i, b_j, b);

  print_adr("       b ", b); // We can see that b is an address
  print_adr("&b[0][0] ", &(b[0][0])); // We can get elements of b
  print_adr("&b[0][7] ", &(b[0][7]));
  print_adr("&b[0][8] ", &(b[0][8]));
  print_adr("&b[1][0] ", &(b[0][8]));
  print_adr("&b[2][3] ", &(b[2][3]));
  printf("Value of b[2][3]: %d\n", b[2][3]); // And the value

  // So what is b?
  // int* b_ptr = b; // Didn't work, b is not a int pointer
  // int** b_ptr = b; // b is also not really a int pointer pointer
  int* b_ptr = *b;
  print_adr("   b_ptr ", b_ptr); // We can see that b is an address


  // So like before
  printf("Value of b[2][3]: %d\n", **(b + 2 * 8 + 3));

  print_adr("       b ", *b);  // but b does point to something
  print_adr("b and 7 more ", *b +  7); // OK, that is b[0][7]

  printf("Value of b[2][3]: %d\n", *(*b + 2 * 8 + 3));

  // In conclusion, a 2-dimensional array is not a pointer to a pointer of integer. 
  // 2-dimensional (and more) are just a special notation for indexing into a 1-dimensional array

  // Can it be made as pointers to pointer. 
  // Yes, but it is not very feasible.
  


}
