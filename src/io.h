#pragma once

/**
 * @brief Читает данные из CSV файла, генерирует "дома" и записывает их в двухстороннюю очередь
 * 
 * @param file_name 
 * @param deque 
 * @return int 0 - успех, 1 - ошибка
 */
int read_csv(const char* file_name, deque* deque);
/**
 * @brief Записывает элементы двухсторонней очереди ("дома") в виде строк в CSV файл
 * 
 * @param file_name 
 * @param deque 
 * @return int 
 */
int write_csv(const char* file_name, deque* deque);
/**
 * @brief Создает таблицу с фиксированной шириной с данными о "домах"
 * 
 * @param file_name 
 * @param d 
 * @return int 
 */
int print_table(const char* file_name, deque* d);