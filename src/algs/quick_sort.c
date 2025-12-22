#include "quick_sort.h"
#include <stdio.h>
#include <assert.h>
#include <limits.h>

static int get_median(deque* d, cmpr compare, int int_low, int int_high) {
    int int_middle = int_low + (int_high - int_low) / 2;
    void* low = deque_get_elem(d, int_low);
    void* middle = deque_get_elem(d, int_middle);
    void* high = deque_get_elem(d, int_high);
    if (compare(low, middle) > 0){
        if (compare(middle, high) > 0){
            return int_middle;
        } else if (compare(low, high) > 0) {
            return int_high;
        } else {
            return int_low;
        }
    } else if (compare(low, high) > 0){
        return int_low;
    } else if (compare(middle, high) > 0){
        return int_high;
    } else {
        return int_middle;
    }
}

static int partition(deque* d, cmpr compare, int int_low, int int_high) {
    int median_index = get_median(d, compare, int_low, int_high);
    void* pivot = deque_get_elem(d, median_index);
    int i = int_low;
    int j = int_high;
    while(1){
        while (compare(deque_get_elem(d, i), pivot) < 0) i++;
        while (compare(deque_get_elem(d, j), pivot) > 0) j--;
        if (i >= j) return j;
        deque_swap(d, i, j);
        i++;
        j--;
    }
}

static void quick_sort_recursion(deque* d, cmpr compare, int int_low, int int_high){
    if (int_low < int_high) {
        int partition_index = partition(d, compare, int_low, int_high);
        quick_sort_recursion(d, compare, int_low, partition_index);
        quick_sort_recursion(d, compare, partition_index + 1, int_high);
    }
}

void quick_sort(deque* d, cmpr compare){
    if (d == NULL) {
        fprintf(stderr, "Deque is NULL\n");
        return;
    }
    if (compare == NULL) {
        fprintf(stderr, "Comparison function is NULL\n");
        return;
    }
    size_t size = deque_get_size(d);
    assert(size <= INT_MAX);
    int int_size = (int)size;
    if (int_size <= 1) return;
    quick_sort_recursion(d, compare, 0, int_size - 1);
}