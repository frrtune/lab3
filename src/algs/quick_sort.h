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
static int get_median(deque* d, cmpr compare, int low, int high);