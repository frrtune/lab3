#include "house.h"

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