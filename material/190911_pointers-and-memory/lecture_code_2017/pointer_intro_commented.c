#include <stdio.h>


#define VAL 6;


int main () {
  int x; // Allocates memory for a local variable of size int
  printf("Address of x: %p\n", (void *) &x); 

  x = 5; // Assigns 5 to x, i.e. stores the integer representation for 5 at the address of x
  printf("Value of   x: %d\n",  x);

  int* x_ptr; // Allocates memory for a local variable of size pointer 
  // The information about int does not affect the size, but only used by the compiler.
  // * - is here used as part of the type deceleration

  x_ptr = &x; // Assigns the address of x to x_ptr
  // & - an operator that returns the address of a variable
  printf("Address of x_ptr: %p\n", (void*) &x_ptr); 
  printf("Value of   x_ptr: %p\n", (void*) x_ptr);

  double y;   // Allocates memory for a local variable of size double
  x_ptr = &y; // Assigns the address of y to x_ptr
  // This generated a warning and not an error. C is not a type-safe language, 
  // but this is often an error so use the warnings.

  x_ptr = &x; // Lets set it back to x

  *x_ptr = 42; // Assigns 42 to the dereferenced address
  // * - is here used as an operator that effects that address that x_ptr points to
  printf("Value of   x: %d\n",  x);

  int* z_ptr; // Lets make another pointer ...
  z_ptr = x_ptr; // and set is equal to x_ptr
  printf("Value of   z_ptr: %p\n", (void*) z_ptr);

  *z_ptr = 3; // Increment the dereference of z_ptr;
  printf("Value of   x: %d\n",  x);

  *z_ptr++; // Be careful with the precedence rules: equals *(z_ptr++)
  printf("Value of   x: %d\n",  x);
  printf("Value of   z_ptr: %p\n", (void*) z_ptr);
  z_ptr--;

  (*z_ptr)++; // This is the intention
  printf("Value of   x: %d\n",  x);
  printf("Value of   z_ptr: %p\n", (void*) z_ptr);

  --*z_ptr; // Alternatively
  printf("Value of   x: %d\n",  x);

  int** x_pptr; // Allocates memory for a pointer to an int pointer ..
  x_pptr = &x_ptr; // .. and assign it the reference to x_ptr
  printf("Value of **x_pptr: %d\n",  **x_pptr);

}