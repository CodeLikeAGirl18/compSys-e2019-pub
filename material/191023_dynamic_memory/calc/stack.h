#ifndef STACK_H
#define STACK_H

struct stack_t {
  int dummy; // replace
};

void stack_init(struct stack_t*);

int stack_empty(struct stack_t*);

void* stack_top(struct stack_t*);

void* stack_pop(struct stack_t*);

int stack_push(struct stack_t*, void*);


#endif
