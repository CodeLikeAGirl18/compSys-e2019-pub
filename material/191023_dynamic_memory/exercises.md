# Exercises for Wednesday 23rd of October

* 8.3 (page 781)
* 8.4 (page 784)
* 8.6 (page 788)
* 8.9 (page 824)
* 8.12 (page 825)
* 8.22 (page 829)
* 8.25 (page 830) (this is the most interesting one)

## And the fun one:

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
