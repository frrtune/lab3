#pragma once

#include <stddef.h>

typedef struct Node {
    void* data;
    struct Node* prev;
    struct Node* next;
} node;

typedef struct Deque {
    node* head;
    node* tail;
    size_t size;
} deque;

size_t deque_get_size(const deque* d);
void* deque_get_elem(deque* d, size_t index);
node* deque_begin(deque* d);
node* deque_end(deque* d);
node* deque_next(node* n);
node* deque_prev(node* n);
void deque_add_begin(deque* d, void* data);
void deque_add_end(deque* d, void* data);
void deque_add_middle(deque* d, void* data, size_t index);
void deque_del_begin(deque* d);
void deque_del_end(deque* d);
void deque_del_middle(deque* d, size_t index);