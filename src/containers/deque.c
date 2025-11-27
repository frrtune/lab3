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