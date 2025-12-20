#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "house.h"

#define BUILDERS_COUNT (sizeof(builders) / sizeof(builders[0]))
#define DISTRICTS_COUNT (sizeof(districts) / sizeof(districts[0]))

int house_compare(const void* h1, const void* h2) {
    const house* house1 = (const house*)h1;
    const house* house2 = (const house*)h2;
    if (house1->year != house2->year) {
        return house2->year - house1->year;
    }
    if (house1->is_elevator != house2->is_elevator) {
        return house2->is_elevator - house1->is_elevator;
    }
    if (house1->is_chute != house2->is_chute) {
        return house2->is_chute - house1->is_chute;
    }
    if (house1->type != house2->type) {
        if (house1->type == BRICK) return -1;
        if (house2->type == BRICK) return 1;
        if (house1->type == MONO) return -1;
        return 1;
    }
    if (house1->avg_area > house2->avg_area) return -1;
    if (house1->avg_area < house2->avg_area) return 1;
    if (house1->apartment_count != house2->apartment_count) return house2->apartment_count - house1->apartment_count;
    return house2->floor_count - house1->floor_count;
}

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

house* generate_house() {
    /*if (d == NULL) {
        fprintf(stderr, "Deque is NULL\n");
        return 1;
    }
    // assert(d != NULL);
    if (n <= 0) {
        fprintf(stderr, "N must be positive\n");
        return 1;
    }*/
    srand(time(NULL));
    
    house* h = malloc(sizeof(house));
    if (h == NULL) {
        fprintf(stderr, "Memory has not been allocated\n");
        return NULL;
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
    return h;
}
