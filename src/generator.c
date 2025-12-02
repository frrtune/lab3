#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "generator.h"
#include "house.h"
#include "containers/deque.h"

#define BUILDERS_COUNT (sizeof(builders) / sizeof(builders[0]))
#define DISTRICTS_COUNT (sizeof(districts) / sizeof(districts[0]))

static const char* builders[] = {
    "Bechtel", "Turner", "Ingrad", "Kiewit", "Fluor", "Haskell", "Granite"
};
static const char* districts[] = {
    "Manhattan", "Brooklyn", "Queens", "Bronx ", "Richmond", "Haskell"
}; 

static const char* random_string(const char* array[], size_t size) {
    return array[rand() % size];
}   

static int random_int(int min, int max) {
    return min + rand() % (max - min + 1);
}

static float random_float(float min, float max) {
    int int_min = (int)(min * 100);
    int int_max = (int)(max * 100);
    int random_val = random_int(int_min, int_max);
    return (float)random_val / 100.0f;
}

int generate_house(deque* d, int n) {
    if (d == NULL) {
        fprintf(stderr, "Deque is NULL\n");
        return 1;
    }
    if (n <= 0) {
        fprintf(stderr, "N must be positive\n");
        return 1;
    }
    srand(time(NULL));
    for (unsigned int i = 0; i < n; i++) {
        house* h = malloc(sizeof(house));
        if (h == NULL) {
            fprintf(stderr, "Memory has not been allocated\n");
            return 1;
        }
        const char* builder = random_string(builders, BUILDERS_COUNT);
        strcpy(h->builder, builder);
        const char* district = random_string(districts, DISTRICTS_COUNT);
        strcpy(h->district, district);
        h->type = rand() % 3;
        h->year = (unsigned int)random_int(1950, 2025);
        unsigned int elevator_probability = rand() % 100;
        if (elevator_probability < 50) {
            h->is_elevator = YES;
        } else {
            h->is_elevator = NO;
        }   
        unsigned int chute_probability = rand() % 100;
        if (chute_probability < 50) {
            h->is_chute = YES;
        } else {
            h->is_chute = NO;
        }
        h->apartment_count = random_int(10, 500);
        h->floor_count = random_int(2, 30);
        h->avg_area = random_float(15.0f, 200.0f);
        deque_push_back(d, h);
    }
    return 0;
}