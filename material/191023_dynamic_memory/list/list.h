#ifndef LIST_H
#define LIST_H

typedef struct list list;

// Create new list.  Initially empty.  NULL on error.
list* list_create();

// Deallocates list.
void list_free(list*);

// Insert element at head of list.  Returns 0 on success.
int list_insert_first(list*, void*);

int list_remove_first(list*, void**);

typedef void* (*map_fn)(void*, void*);

void list_map(list*, map_fn, void*);

#endif
