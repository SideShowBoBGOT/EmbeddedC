#include "../include/list.h"
#include "node.h"

#include <stdlib.h>

list* list__new(list__cpy cpy, list__dtor dtor) {
    list* new_list = (list*)malloc(sizeof(list));
    new_list->root = NULL;
    new_list->tail = NULL;
    new_list->length = 0;
    new_list->dtor = dtor;
    new_list->cpy = cpy;
    return new_list;
}

void list__push_front(list* self, void* data, size_t size) {
    node* new_node = node__new(data, self->cpy);
    if(self->root == NULL) {
        self->root = new_node;
        self->tail = new_node;
    } else {
        new_node->next = self->root;
        self->root->prev = new_node;
        self->root = new_node->next;
    }
    ++self->length;
}

void list__push_back(list* self, void* data, size_t size) {
    node* new_node = node__new(data, self->cpy);
    if(self->tail == NULL) {
        self->root = new_node;
        self->tail = new_node;
    } else {
        new_node->prev = self->tail;
        self->tail->next = new_node;
        self->tail = new_node;
    }
    ++self->length;
}

int list__pop_front(list* self) {
    if(self->root == NULL) {
        return -1;
    }
    node* old_root = self->root;
    node* new_root = self->root->next;
    if(new_root != NULL) {
        new_root->prev = NULL;
        self->root = new_root;
    } else {
        self->tail = NULL;
        self->root = NULL;
    }
    free(old_root->data);
    free(old_root);
    --self->length;
    return 0;
}

int list__pop_back(list* self) {
    if(self->tail == NULL) {
        return -1;
    }
    node* old_tail = self->tail;
    node* new_tail = self->tail->prev;
    if(new_tail != NULL) {
        new_tail->next = NULL;
        self->tail = new_tail;
    } else {
        self->tail = NULL;
        self->root = NULL;
    }
    free(old_tail->data);
    free(old_tail);
    --self->length;
    return 0;
}

int list__at(const list* self, unsigned index, void** data) {
    if(index >= self->length) {
        return -1;
    }
    node* n = self->root;
    for(unsigned i = 0; i < index; ++i) {
        n = n->next;
    }
    *data = n->data;
    return 0;
}

void list__free(list* self) {
    node* n = self->root;
    while(n != NULL) {
        node* old = n;
        n = n->next;
        self->dtor(old->data);
        free(old);
    }
    self->root = NULL;
    self->tail = NULL;
    self->length = 0;
    free(self);
}
