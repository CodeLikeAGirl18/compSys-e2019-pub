# Exercises for Wednesday 23rd of October

# Implementing a stack

The `calc/` directory contains the code for a simple calculator that
uses Reverse Polish Notation.  For example, to add two numbers and
print the result we would input `2 3 + p`.  Unfortunately I ran late
and forgot to finish the implementation of `stack.h` and `stack.c`.
Finish it for me so the stack calculator will work.

# List implementation

Change the implementation of the list library covered in the lectures
(`list.c`) to use a different representation.  Do not change `list.h`.
For example, an implementation with doubly linked lists:

    struct node {
      void *elem;
      struct node *next;
      struct node *prev;
    };

    struct list {
      struct node *first;
      struct node *last;
    };

Or one where the representation is a flat array:

    struct list {
      void **data;
      int length;
    };

Consider how these affect the performance of the API, without changing
its semantics.