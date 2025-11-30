#pragma once
#include <stdbool.h>
#define NO (bool)0 
#define YES (bool)1

typedef enum House_type {
    PANEL,
    BRICK,
    MONO
} house_type;

typedef struct House {
    char builder[100];
    char district[100];
    house_type type;
    unsigned int year;
    bool is_elevator;
    unsigned int apartment_count;
    unsigned int floor_count;
    float avg_area;
} house;

int house_compare(const void* h1, const void* h2);