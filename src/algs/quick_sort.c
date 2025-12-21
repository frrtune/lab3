#include <quick_sort.h>

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