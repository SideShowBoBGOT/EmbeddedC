#include "list.h"

#include <stdlib.h>

static node* create_node(void* data, size_t size) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->next = NULL;
    new_node->prev = NULL;
    new_node->data = malloc(size);
    memcpy(new_node->data, data, size);
    return new_node;
}

list list__new() {
    list l = {.root=NULL, .tail=NULL};
    return l;
}

void list__push_front(list* self, void* data, size_t size) {
    node* new_node = create_node(data, size);
    if(self->root == NULL) {
        self->root = new_node;
        self->tail = new_node;
    } else {
        new_node->next = self->root;
        self->root->prev = new_node;
        self->root = new_node->next;
    }
}

void list__push_back(list* self, void* data, size_t size) {
    node* new_node = create_node(data, size);
    if(self->tail == NULL) {
        self->root = new_node;
        self->tail = new_node;
    } else {
        new_node->prev = self->tail;
        self->tail->next = new_node;
        self->tail = new_node;
    }
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
    return 0;
}

void list__free(list* self) {
    node* n = self->root;
    while(n != NULL) {
        node* old = n;
        n = n->next;
        free(old->data);
        free(old);
    }
}




