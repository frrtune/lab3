#include "sort.h"
#include "../containers/deque.h"

void shaker_sort(deque* d, cmpr compare) {
    if (d == NULL || compare == NULL || deque_get_size(d) <= 1) return;
    unsigned int done = 1;
    size_t current_start = 0;
    size_t current_end = deque_get_size(d) - 1;
    while (done && (current_start < current_end)) {
        done = 0;
        for (size_t i = current_start; i < current_end; i++) {
            void* current_elem = deque_get_elem(d, i);
            void* next_elem = deque_get_elem(d, i + 1);
            if (compare(current_elem, next_elem) > 0) {
                deque_swap(d, i, i + 1);
                done = 1;
            }
        }
        if (done == 0) break;
        current_end--;
        for (size_t i = current_end; i > current_start; i--) {
            void* current_elem = deque_get_elem(d, i);
            void* next_elem = deque_get_elem(d, i - 1);
            if (compare(current_elem, next_elem) < 0) {
                deque_swap(d, i, i - 1);
                done = 1;
            }
        }
        current_start++;
    }
}