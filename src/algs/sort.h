#pragma once

typedef int (*cmpr)(const void*, const void*);
void shaker_sort(deque* d, cmpr compare);