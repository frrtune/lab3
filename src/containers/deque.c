#include "deque.h"

deque* deque_init(){
    deque* new_deque = malloc(sizeof(deque));
    if (new_deque == NULL) return NULL;
    new_deque->head = NULL;
    new_deque->tail = NULL;
    new_deque->size = 0;
    return new_deque;
}