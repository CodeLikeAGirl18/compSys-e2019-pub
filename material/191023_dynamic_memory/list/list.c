#include <stdlib.h>
#include "list.h"

struct list_node {
  void *data;
  struct list_node *next;
};

struct list {
  struct list_node *head;
};

list* list_create() {
  struct list *list = malloc(sizeof(list));
  list->head = NULL;
  return list;
}

void list_free(list* list) {
  struct list_node *node = list->head;
  while (node != NULL) {
    struct list_node *next = node->next;
    free(node);
    node = next;
  }
  free(list);
}

int list_insert_first(list* list, void* data) {
  struct list_node *new_head = malloc(sizeof(struct list_node));
  new_head->data = data;
  new_head->next = list->head;
  list->head = new_head;
  return 0;
}

int list_remove_first(list* list, void** dest) {
  if (list->head == NULL) {
    return 1;
  }
  *dest = list->head->data;
  struct list_node *old_head = list->head;
  list->head = old_head->next;
  free(old_head);
  return 0;
}

void list_map(list* list, map_fn f, void *aux) {
  struct list_node *node = list->head;
  while (node != NULL) {
    node->data = f(node->data, aux);
    node = node->next;
  }
}
