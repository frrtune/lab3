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

void deque_push_front(deque* d, void* data){
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

void deque_push_back(deque* d, void* data){
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

void deque_insert(deque* d, void* data, size_t index){
    if (d == NULL || index >= d->size) return;
    if (index == 0) {
        deque_push_front(d, data);
        return;
    }
    if (index == d->size) {
        deque_push_back(d, data);
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

void deque_swap(deque* d, size_t index1, size_t index2) {
    if (d == NULL || index1 >= d -> size || index2 >= d -> size) return;
    if (index1 == index2) return;
    node* node1 = d->head;
    for (size_t i = 0; i < index1; i++) node1 = node1->next;
    node* node2 = d->head;
    for (size_t i = 0; i < index2; i++) node2 = node2->next;
    void* temp_data = node1->data;
    node1->data = node2->data;
    node2->data = temp_data;
}

deque* arr_to_deque(void** arr, size_t size) {
    if (arr == NULL) return NULL;
    deque* d = deque_init();
    if (d == NULL) return NULL;
    for (size_t i = 0; i < size; i++) {
        deque_push_back(d, arr[i]);
    }
    return d;
}

void** deque_to_arr(deque* d) {
    if (d == NULL || d->size == 0) return NULL;
    void** arr = calloc(d->size, sizeof(void*));
    if (arr == NULL) return NULL;
    node* current = d->head;
    for (size_t i = 0; i <  d->size; i++) {
        arr[i] = current->data;
        current = current->next;
    }
    return arr;
}

void deque_free(deque* d) {
    if (d == NULL) return;
    node* current_node = d->head;
    while (current_node != NULL) {
        node* next_node = current_node->next;
        free(current_node->data);
        free(current_node);
        current_node = next_node;
    }
    free(d);
}