#include "args.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static const argument_t arguments[] = {
    {"generate", 'g', _INT, NULL, "Generates N strings of random data"},
    {"out", 'o', _STR, NULL, "Output in specified file"},
    {"sort", 's', _END, NULL, "Sorts data"},
    {"in", 'i', _STR, NULL, "Input from specified file"},
    {"type", 't', _STR, NULL, "Sort type: ascending (asc) or descending (desc)"},
    {"print", 'P', _END, NULL, "Prints data in a table"},
    {NULL, '\0', _END, NULL, NULL}
};

int parse_args(int argc, char* argv[], arg_params* params) {
    params->mode = NONE;
    params->input_file = NULL;
    params->output_file = NULL;
    params->str_count = 0;
    params->asc_or_desc = 1;
    if (argc == 1) {
        puts("HELP");
        for (const argument_t *a = arguments; a-> long_name != NULL; ++a){
            printf("--%s OR -%c: %s\n", a->long_name, a->short_name, a->description);
        }
        return 2;
    }
    for (size_t i = 1; i < argc; ++i) {
        char *curr_arg = argv[i];
        size_t len = strlen(curr_arg);
        if (len > 2 && curr_arg[0] == '-' && curr_arg[1] == '-') {
            char* arg_name = curr_arg + 2;
            argument_t *found_arg = NULL;
            for (const argument_t *arg = arguments; arg->long_name != NULL; arg++){
                if (strcmp(arg_name, arg->long_name) == 0){
                    found_arg = (argument_t *)arg;
                    break;
                }
            } 
            if (found_arg == NULL) {
                fprintf(stderr, "%s\n", "UNKNOWN OPERATION");
                return 1;
            }
            switch (found_arg -> tag) {
                case _STR: {
                    if (i + 1 >= argc) {
                        fprintf(stderr, "INVALID SYNTAX, USAGE: %s\n", found_arg->description);
                        return 1;
                    }
                    if (strcmp(arg_name, "in") == 0) {
                        params->input_file = argv[++i];
                    } else if (strcmp(arg_name, "out") == 0) {
                        params->output_file = argv[++i];
                    } else if (strcmp(arg_name, "type") == 0) {
                        char* type = argv[++i];
                        if (strcmp(type, "asc") == 0) {
                            params->asc_or_desc = 1;
                        } else if (strcmp(type, "desc") == 0) {
                            params->asc_or_desc = 0;
                        } else {
                            fprintf(stderr, "INVALID SORT TYPE\n");
                            return 1;
                        }
                    }
                    break;
                }
                case _INT: {
                    if (i + 1 >= argc) {
                        fprintf(stderr, "INVALID SYNTAX, USAGE: %s\n", found_arg->description);
                        return 1;
                    }
                    if (strcmp(arg_name, "generate") == 0) {
                        params->mode = GENERATE;
                        params->str_count = atoi(argv[++i]);
                        if (params->str_count <= 0) {
                            fprintf(stderr, "Number of strings must be positive");
                            return 1;
                        }
                    }
                    break;
                }
                case _END: {
                    if (strcmp(arg_name, "sort") == 0) {
                        if (params->mode != NONE) {
                            fprintf(stderr, "The program can work in only one mode at a time");
                            return 1;
                        }
                        params->mode = SORT;
                    } else if (strcmp(arg_name, "print") == 0) {
                        if (params->mode != NONE) {
                            fprintf(stderr, "The program can work in only one mode at a time");
                            return 1;
                        }
                        params->mode = PRINT;
                    }
                    break;
                }
            }
        } else if (len > 1 && curr_arg[0] == '-') {
            char* arg_name = curr_arg + 1;
            argument_t *found_arg = NULL;
            for (const argument_t *arg = arguments; arg->long_name != NULL; arg++){
                if ((arg_name[0] == arg->short_name) && (strlen(arg_name) == 1)){
                    found_arg = (argument_t *)arg;
                    break;
                }
            } 
            if (found_arg == NULL) {
                fprintf(stderr, "%s\n", "UNKNOWN OPERATION");
                return 1;
            }
            switch (found_arg -> tag) {
                case _STR: {
                    if (i + 1 >= argc) {
                        fprintf(stderr, "INVALID SYNTAX, USAGE: %s\n", found_arg->description);
                        return 1;
                    }
                    if (strcmp(arg_name, "i") == 0) {
                        params->input_file = argv[++i];
                    } else if (strcmp(arg_name, "o") == 0) {
                        params->output_file = argv[++i];
                    } else if (strcmp(arg_name, "t") == 0) {
                        char* type = argv[++i];
                        if (strcmp(type, "A") == 0) {
                            params->asc_or_desc = 1;
                        } else if (strcmp(type, "D") == 0) {
                            params->asc_or_desc = 0;
                        } else {
                            fprintf(stderr, "INVALID SORT TYPE\n");
                            return 1;
                        }
                    }
                    break;
                }
                case _INT: {
                    if (i + 1 >= argc) {
                        fprintf(stderr, "INVALID SYNTAX, USAGE: %s\n", found_arg->description);
                        return 1;
                    }
                    if (strcmp(arg_name, "g") == 0) {
                        params->mode = GENERATE;
                        params->str_count = atoi(argv[++i]);
                        if (params->str_count <= 0) {
                            fprintf(stderr, "Number of strings must be positive");
                            return 1;
                        }
                    }
                    break;
                }
                case _END: {
                    if (strcmp(arg_name, "s") == 0) {
                        if (params->mode != NONE) {
                            fprintf(stderr, "The program can work in only one mode at a time");
                            return 1;
                        }
                        params->mode = SORT;
                    } else if (strcmp(arg_name, "P") == 0) {
                        if (params->mode != NONE) {
                            fprintf(stderr, "The program can work in only one mode at a time");
                            return 1;
                        }
                        params->mode = PRINT;
                    }
                    break;
                }
            }
        }
    }
    return 0;
}