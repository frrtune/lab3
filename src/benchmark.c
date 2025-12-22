#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "house/house.h"
#include "containers/deque.h"
#include "algs/sort.h"
#include "algs/quick_sort.h"

int main() {
    int sizes[] = {500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000};
    int count_sizes = sizeof(sizes) / sizeof(sizes[0]);
    FILE* file = fopen("benchmark.csv", "w");
    if (file == NULL) {
        fprintf(stderr, "No file has been created");
        return 1;
    }
    srand(100);
    for (int i = 0; i < count_sizes; i++) {
        int size = sizes[i];
        srand(100 + size);
        deque* d = deque_init();
        for (int j = 0; j < size; j++) {
            deque_push_back(d, generate_house());
        }
        clock_t start = clock();
        quick_sort(d, house_compare);
        clock_t end = clock();
        double total = (double)(end - start) / CLOCKS_PER_SEC;
        fprintf(file, "%d, %.10f\n", size, total);
        deque_free(d);
    }
    fclose(file);
    return 0;
}