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
 * @brief Получение указателя на предыдущий элемент
 * 
 * @param n 
 * @return node* 
 */
node* deque_prev(node* n);
/**
 * @brief Добавление элемента в начало
 * 
 * @param d 
 * @param data 
 */
void deque_push_front(deque* d, void* data);
/**
 * @brief Добавление элемента в конец
 * 
 * @param d 
 * @param data 
 */
void deque_push_back(deque* d, void* data);
/**
 * @brief Вставка элемента по индексу
 * 
 * @param d 
 * @param data 
 * @param index 
 */
void deque_insert(deque* d, void* data, size_t index);
/**
 * @brief Удаление элемента из начала
 * 
 * @param d 
 */
void deque_del_begin(deque* d);
/**
 * @brief Удаление элемента из конца
 * 
 * @param d 
 */
void deque_del_end(deque* d);
/**
 * @brief Удаление элемента по индексу
 * 
 * @param d 
 * @param index 
 */
void deque_del_middle(deque* d, size_t index);
/**
 * @brief Поменять местами два элемента по индексам
 * 
 * @param d 
 * @param index1 
 * @param index2 
 */
void deque_swap(deque* d, size_t index1, size_t index2);
/**
 * @brief Преобразует массив в двухстороннюю очередь
 * 
 * @param arr 
 * @param size 
 * @return deque* 
 */
deque* arr_to_deque(void** arr, size_t size);
/**
 * @brief Преобразует двухстороннюю очередь в массив
 * 
 * @param d 
 * @return void** 
 */
void** deque_to_arr(deque* d);
/**
 * @brief Освобождает место в памяти, занятое двухсторонней очередью
 * 
 * @param d 
 */
void deque_free(deque* d);