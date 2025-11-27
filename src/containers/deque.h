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