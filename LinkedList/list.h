#ifndef LINKEDLIST_LIST_H
#define LINKEDLIST_LIST_H

#include <string.h>

typedef struct node_struct {
    void* data;
    struct node_struct* next;
    struct node_struct* prev;
} node;

typedef struct list_struct {
    node* root;
    node* tail;
} list;

list list__new();
void list__push_front(list* self, void* data, size_t size);
void list__push_back(list* self, void* data, size_t size);
int list__pop_front(list* self);
int list__pop_back(list* self);
void list__free(list* self);

#endif //LINKEDLIST_LIST_H
