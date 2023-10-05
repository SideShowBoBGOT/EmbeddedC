#ifndef LINKEDLIST_LIST_H
#define LINKEDLIST_LIST_H

#include <string.h>

struct node_struct;
typedef struct node_struct node;

typedef void(*list__dtor)(void*);
typedef void*(*list__cpy)(const void*);

typedef struct list_struct {
    unsigned length;
    node* root;
    node* tail;
    list__dtor dtor;
    list__cpy cpy;
} list;

list* list__new(list__dtor dtor, list__cpy cpy);
void list__push_front(list* self, void* data, size_t size);
void list__push_back(list* self, void* data, size_t size);
int list__pop_front(list* self);
int list__pop_back(list* self);
int list__at(const list* self, unsigned index, void** data);
void list__free(list* self);

#endif //LINKEDLIST_LIST_H
