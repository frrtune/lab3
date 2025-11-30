#pragma once

#include <stddef.h>

typedef enum {
    _END,
    _STR,
    _INT
} arg_tag_t;

typedef struct Argument {
    const char* long_name;
    char short_name;
    arg_tag_t tag;
    void* value;
    const char *description;
} argument_t;

typedef enum {
    NONE,
    GENERATE,
    SORT,
    PRINT
} program_mode;

typedef struct {
    program_mode mode;
    char* input_file;
    char* output_file;
    int str_count;
    int asc_or_desc;
} arg_params;

/**
 * @brief Функция-парсер: анализирует аргументы и определяет режим работы программы
 * 
 * @param argc количество аргументов
 * @param argv указатель на массив указателей (строк с аргументами)
 * @param params указатель на структуру, которая хранит параметры
 * @return int 0, если выполнено успешно, 1, если ошибка, 2, если запрошена справка
 */
int parse_args(int argc, char* argv[], arg_params* params);