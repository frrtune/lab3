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

/**
 * @brief Инициализация двухсторонней очереди
 * 
 * @return deque* 
 */
deque* deque_init();
/**
 * @brief Получение размера двухсторонней очереди
 * 
 * @param d 
 * @return size_t 
 */
size_t deque_get_size(const deque* d);
/**
 * @brief Получение элемента по индексу
 * 
 * @param d 
 * @param index 
 * @return void* 
 */
void* deque_get_elem(deque* d, size_t index);
/**
 * @brief Получение указателя на начало
 * 
 * @param  
 * @return node* 
 */
node* deque_begin(deque* d);
/**
 * @brief Получение указателя на конец
 * 
 * @param d 
 * @return node* 
 */
node* deque_end(deque* d);
/**
 * @brief Получение указателя на следующий элемент
 * 
 * @param n 
 * @return node* 
 */
node* deque_next(node* n);
/**
 * @brief олучение указателя на предыдущий элемент
 * 
 * @param n 
 * @return node* 
 */
node* deque_prev(node* n);
void deque_push_front(deque* d, void* data);
void deque_push_back(deque* d, void* data);
void deque_insert(deque* d, void* data, size_t index);
void deque_del_begin(deque* d);
void deque_del_end(deque* d);
void deque_del_middle(deque* d, size_t index);
void deque_swap(deque* d, size_t index1, size_t index2);
deque* arr_to_deque(void** arr, size_t size);
void** deque_to_arr(deque* d);
void deque_free(deque* d);