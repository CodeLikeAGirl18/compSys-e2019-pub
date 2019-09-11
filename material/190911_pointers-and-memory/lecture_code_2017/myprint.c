#include <stdio.h>


#define SUCCESS 1

void* stackBot;

// Convention dictates that stacks grows downwards.
// Thus the bottom of a stack is
int print_adr(char* str, void* var) {
  unsigned long reladr = 0x8400 -
    (unsigned long int) stackBot +
    (unsigned long int) var;
  unsigned long ones = -1;
  printf("Address of %s: 0x", str);
  for (int i = 3 ; i >= 0 ; i--) {
    printf("%x", (unsigned int) (reladr >> (4 * i)));
    reladr = reladr & (ones >> (sizeof(reladr) * 8 - 4 * i));
  }
  printf("\n");
  return SUCCESS;
}

int print_array(int length, int intarray[length]) {
  printf("[");
  for (int i = 0 ; i < length - 1 ; i++) {
    if (intarray[i] < 10) {
      printf(" ");
    }
    printf("%d, ", intarray[i]);
  }
  if (intarray[length - 1] < 10) {
    printf(" ");
  }
  printf("%d", intarray[length - 1]);
  printf("]\n");

  return SUCCESS;
}

int print_2Darray(int length_i, int length_j, int intarray[length_i][length_j]) {
  printf("[");
  for (int i = 0 ; i < length_i - 1 ; i++) {
    print_array(length_j, intarray[i]);
    printf(" ");
  }
  print_array(length_j, intarray[length_i - 1]);
  printf("]\n");

  return SUCCESS;
}
