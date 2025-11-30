#pragma once

typedef int (*cmpr)(const void*, const void*);
/**
 * @brief Сортировка перемешиванием - модификация пузырьковой сортировки: проходит по массиву слева направо и справа налево, для оптимизации каждый раз изменяется начало и конец сортировки
 * 
 * @param d 
 * @param compare 
 */
void shaker_sort(deque* d, cmpr compare);