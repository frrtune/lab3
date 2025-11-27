#include "house.h"

int house_compare(const house* house1, const house* house2){
    if (house1->year < house2->year) return -1;
    if (house1->year > house2->year) return 1;
    return 0;
}