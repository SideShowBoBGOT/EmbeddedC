#ifndef LINKEDLIST_NODE_H
#define LINKEDLIST_NODE_H

#include <stdlib.h>

typedef struct node_struct {
    void* data;
    struct node_struct* next;
    struct node_struct* prev;
} node;

node* node__new(void* data, void*(*data_copy)(const void*));

#endif //LINKEDLIST_NODE_H
