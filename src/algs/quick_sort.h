#pragma once

#include "../containers/deque.h"

typedef int (*cmpr)(const void*, const void*);

/**
 * @brief Быстрая сортирвока
 * 
 * @param d 
 * @param compare 
 */
void quick_sort(deque* d, cmpr compare);


/**
 * @brief Нахождение медианы
 * 
 * @param d 
 * @param compare 
 * @param low 
 * @param high 
 * @return int 
 */
static int get_median(deque* d, cmpr compare, int int_low, int int_high);

/**
 * @brief Partition выбирает некоторый элемент массива и переставляет элементы участка массива таким образом, чтобы массив разбился на 2 части: левая часть содержит элементы, которые меньше этого элемента, а правая часть содержит элементы, которые больше или равны этого элемента.
 * 
 * @param d 
 * @param compare 
 * @param int_low 
 * @param int_high 
 * @return int 
 */
static int partition(deque* d, cmpr compare, int int_low, int int_high);

/**
 * @brief Рекурсия для быстрой сортировки
 * 
 * @param d 
 * @param compare 
 * @param int_low 
 * @param int_high 
 */
static void quick_sort_recursion(deque* d, cmpr compare, int int_low, int int_high);

/**
 * @brief Основная функция быстрой сортирвоки
 * 
 * @param d 
 * @param compare 
 */
void quick_sort(deque* d, cmpr compare);