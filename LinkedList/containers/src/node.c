#include "node.h"

node* node__new(void* data, void*(*data_copy)(const void*)) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->next = NULL;
    new_node->prev = NULL;
    new_node->data = data_copy(data);
    return new_node;
}
