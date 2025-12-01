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
    bool is_chute;
    unsigned int apartment_count;
    unsigned int floor_count;
    float avg_area;
} house;

/**
 * @brief Функция-компаратор: сравнивает дома по шести параметрам в следующем порядке:
 * 1. Год постройки (чем больше год, тем лучше)
 * 2. Наличие лифта
 * 3. Наличие мусоропровода
 * 4. Тип (кирпичный > монолитный > панельный)
 * 5. Средняя площадь квартир (чем больше, тем лучше)
 * 6. Количество квартир (чем больше, тем лучше)
 * 7. Количество этажей (чем больше, тем лучше)
 * 
 * @param h1 указатель на первый дом
 * @param h2 указатель на второй дом
 * @return int отрицательное число, если h1 < h2, положительное, если h1 > h2, 0, если h1 = h2
 */
int house_compare(const void* h1, const void* h2);