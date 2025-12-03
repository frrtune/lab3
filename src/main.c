#include <stdio.h>
#include "../args/args.h"
#include "algs/sort.h"
#include "containers/deque.h"
#include "generator.h"
#include "io.h"

int main(int argc, char* argv[]){
    arg_params params;
    int ret = parse_args(argc, argv, &params);
    if (ret == 2) return 2;
    if (ret == 1) return 1;
    deque* d = deque_init();
    if (d == NULL) return 1;
    switch (params.mode) {
        case GENERATE:
            ret = generate_house(d, params.str_count);
            if (ret == 1) return 1;
            else {
                ret = write_csv(params.output_file, d);
            }
        case SORT:
            ret = read_csv(params.input_file, d);
    }
}