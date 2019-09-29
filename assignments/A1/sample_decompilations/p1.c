#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

long read_long(char *str);
long my_abs_simple(long x);


/*
 * given a number x, computes the
 * absolute value of x using XOR. */
long my_abs(long x) {
  long sign_mask = x >> 63;     /* if MSB of x is 1, then sign_mask is -1 (ie. all ones);
                                 * else, sign_mask is 0. */
                                
  long _x = x ^ sign_mask;      /* if sign_mask is 0, then _x == x;
                                 * else _x == ~x (bitwise negation, ie. x with all bits flipped)
                                 *
                                 * this uses the fact that b ^ 1 == ~b for any bit b. */
                                
  long abs_x = _x - sign_mask;  /* if sign_mask is  0  ==>  _x == x   ==>  _x - 0    == x
                                 * if sign_mask is -1  ==>  _x == ~x  ==>  ~x - (-1) == -x
                                 *
                                 * this uses the fact that ~a - (-1) == -a for all a. */

  return abs_x;
}


int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <numerical>\n", argv[0]);
    return 1;
  }

  long user_input = read_long(argv[1]);

  printf("my_abs(%ld) == %ld\n", user_input, my_abs(user_input));
}






// reads a long from user input, exiting if input is invalid.
long read_long(char *str) {
  char *y;
  long x = strtol(str, &y, 10);
  if (y == str) exit(1);
  return x;
}



/* a simpler translation of p1. Since
 * this is semantically equivalent to p1,
 * it is just as valid a translation as my_abs().
 * 
 * given a number x, computes the absolute
 * value of x using numerical negation. */
long my_abs_simpler(long x) {
  return x < 0 ? -x : x;
}
