#include <stdio.h>
void print_arr(long *arr);


/*
 * remove all occurances of "remove_this" from
 * the null-terminated long array "arr". */
long filter_array(long remove_this, long *arr) {

  long old_p = 0;        // used to iterate the old array
  long new_p = 0;        // used to keep track of the current tail of new array
                         
  while(arr[old_p]) {    // iterate until a zero-entry is found.


    /* if current entry is NOT what we are looking for; move 
     * element at old_p to new_p, then increment both pointers.
     *
     * if current entry IS what we are looking for, then new_p is
     * not incremented, which means that on next iteration and
     * henceforth, the tail of the data structure is pushed up. */
    if (arr[old_p] != remove_this) {
      arr[new_p] = arr[old_p];

      new_p++;
    }

    // old_p is incremented on each iteration.
    old_p++;
  }

  /* after iteration, make sure to append
   * a null terminator so the data structure
   * can assume its new shape. */
  arr[new_p] = 0;

  /* the program returns the number of discarded
   * occurances of remove_this. */
  long new_length = old_p - new_p;
  return new_length;
}



int main() {

  long my_arr[10] = {111111, -4, 11333377, 67, 4, 255, 42, -255, 4, 0};
  print_arr(my_arr);


  long remove_this = 4;
  int num_removed = (int) filter_array(remove_this, my_arr);

  printf("removed %d elements from array :)\n", num_removed);

  print_arr(my_arr);
}



/* don't worry about this function, just know
 * that it prints a null-terminated array
 * (excluding the null terminator). */
void print_arr(long *arr) {
  printf("[");
  while (*arr) {
    printf("%ld, ", *(arr++));
  }
  printf("\b\b]\n");
}
