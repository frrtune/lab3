#include "deque.h"

deque* deque_init(){
    deque* new_deque = malloc(sizeof(deque));
    if (new_deque == NULL) return NULL;
    new_deque->head = NULL;
    new_deque->tail = NULL;
    new_deque->size = 0;
    return new_deque;
}

size_t deque_get_size(const deque* d){
    if (d == NULL) return 0;
    return d->size;
}

void* deque_get_elem(deque* d, size_t index){
    if (d == NULL || d->head == NULL || index >= d->size){
        return NULL;
    }
    node* current_node = d->head;
    for (size_t i = 0; i < index; i++){
        current_node = current_node->next;
    }
    return current_node->data;
}

node* deque_begin(deque* d) {
    if (d == NULL) return NULL;
    return d->head;
}

node* deque_end(deque* d) {
    if (d == NULL) return NULL;
    return d->tail;
}

node* deque_next(node* n) {
    if (n == NULL) return NULL;
    return n->next;
}

node* deque_prev(node* n) {
    if (n == NULL) return NULL;
    return n->prev;
}

void deque_add_begin(deque* d, void* data){
    if (d == NULL) return;
    node* new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = d->head;
    if (d->head != NULL){
        d->head->prev = new_node;
    }
    d->head = new_node;
    if (d->tail == NULL) {
        d->tail = new_node;
    }
    d->size++;
}

void deque_add_end(deque* d, void* data){
    if (d == NULL) return;
    node* new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = d->tail;
    if (d->tail != NULL){
        d->tail->next = new_node;
    }
    d->tail = new_node;
    if (d->head == NULL) {
        d->head = new_node;
    }
    d->size++;
}

void deque_add_middle(deque* d, void* data, size_t index){
    if (d == NULL || index >= d->size) return;
    if (index == 0) {
        deque_add_begin(d, data);
        return;
    }
    if (index == d->size) {
        deque_add_end(d, data);
        return;
    }

    node* current_node = d->head;
    for (size_t i = 0; i < index; i++){
        current_node = current_node->next;
    }
    node* new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->next = current_node;
    new_node->prev = current_node->prev;
    current_node->prev->next = new_node;
    current_node->prev = new_node;
    d->size++;
}

void deque_del_begin(deque* d){
    if (d == NULL || d->head == NULL) return;
    node* old_head = d->head;
    d->head = old_head->next;
    if (d->head != NULL){
        d->head->prev = NULL;
    } else {
        d->tail = NULL;
    }
    free(old_head);
    d->size--;
}

void deque_del_end(deque* d){
    if (d == NULL || d->tail == NULL) return;
    node* old_tail = d->tail;
    d->tail = old_tail->prev;
    if (d->tail != NULL){
        d->tail->next = NULL;
    } else {
        d->head = NULL;
    }
    free(old_tail);
    d->size--;
}

void deque_del_middle(deque* d, size_t index){
    if (d == NULL || index >= d->size) return;
    if (index == 0) {
        deque_del_begin(d);
        return;
    }
    if (index == d->size - 1) {
        deque_del_end(d);
        return;
    }

    node* current_node = d->head;
    for (size_t i = 0; i < index; i++){
        current_node = current_node->next;
    }
    current_node->prev->next = current_node->next;
    current_node->next->prev = current_node->prev;
    free(current_node);
    d->size--;
}