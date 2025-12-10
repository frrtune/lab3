#include <stdio.h>
#include "../args/args.h"
#include "algs/sort.h"
#include "containers/deque.h"
#include "house.h"
#include "io.h"
#include "house.h"

int main(int argc, char* argv[]){
    arg_params params;
    int ret = parse_args(argc, argv, &params);
    if (ret == 2) return 2;
    if (ret == 1) return 1;
    deque* d = deque_init();
    if (d == NULL) return 1;
    switch (params.mode) {
        case GENERATE:
            for (size_t i = 0; i < params.str_count; i++) {
                house* h = generate_house();
                if (h == NULL) {
                    fprintf(stderr, "Failed to generate house\n");
                    return 1;
                }
                deque_push_back(d, h);
            }
            ret = write_csv(params.output_file, d);
            break;
        case SORT:
            ret = read_csv(params.input_file, d);
            if (ret == 1) return 1;
            else {
                shaker_sort(d, house_compare);
                if (params.asc_or_desc == 1) {
                    reverse_deque(d);
                }
                ret = write_csv(params.output_file, d);
                break;
            }
        case PRINT:
            ret = read_csv(params.input_file, d);
            if (ret == 1) return 1;
            ret = print_table(params.output_file, d);
            break;
        default:
            fprintf(stderr, "No mode has been chosen\n");
            return 1;
    }
    return ret;
}