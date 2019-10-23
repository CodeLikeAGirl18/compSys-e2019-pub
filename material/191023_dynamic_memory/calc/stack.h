#ifndef STACK_H
#define STACK_H

struct list_t {
  void* data;
  struct list_t* next;
};

struct stack_t {
  struct list_t* top;
};

void stack_init(struct stack_t*);

int stack_empty(struct stack_t*);

void* stack_top(struct stack_t*);

void* stack_pop(struct stack_t*);

int stack_push(struct stack_t*, void*);


#endif
