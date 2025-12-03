#include "io.h"
#include "../containers/deque.h"
#include "house.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define EPS 0.0001f

int read_csv(const char* file_name, deque* deque) {
    FILE* file_ptr = stdin;
    if (file_name) {
        file_ptr = fopen(file_name, "r");
        if (file_ptr == NULL) {
            fprintf(stderr, "Cannot open file\n");
            return 1;
        }
    }
    char line[1000];
    int line_count = 0;
    while (fgets(line, sizeof(line), file_ptr)) {
        line_count++;
        char* ptr = line;
        while (*ptr == ' ' || *ptr == '\t') ptr++;
        if (*ptr == '\0' || *ptr == '\n') continue;
        size_t len = strlen(ptr);
         if (len > 0 && ptr[len-1] == '\n') {
            ptr[len-1] = '\0';
        }
        house* h = malloc(sizeof(house));
        if (h == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            if (file_name != NULL) fclose(file_ptr);
            return 1;
        }
        int field = 0;
        char* token = strtok(ptr, ",");
        while (token != NULL) {
            switch (field) {
                case 0:
                    strncpy(h->builder, token, sizeof(h->builder)-1);
                    h->builder[sizeof(h->builder)-1] = '\0';
                    break;
                case 1:
                    strncpy(h->district, token, sizeof(h->district)-1);
                    h->district[sizeof(h->district)-1] = '\0';
                    break;
                case 2:
                    if (strcmp(token, "PANEL") == 0) {
                        h->type = PANEL;
                    } else if (strcmp(token, "BRICK") == 0) {
                        h->type = BRICK;
                    } else if (strcmp(token, "MONO") == 0) {
                        h->type = MONO;
                    } else {
                        fprintf(stderr, "Invalid house type at line %d: %s\n", line_count, token);
                        free(h);
                        if (file_name != NULL) fclose(file_ptr);
                        return 1;
                    }
                    break;
                case 3:
                    h->year = (unsigned int)atoi(token);
                    if (h->year < 1500 || h->year > 3000) {
                        fprintf(stderr, "Invalid year at line %d: %s\n", line_count, token);
                        free(h);
                        if (file_name != NULL) fclose(file_ptr);
                        return 1;
                    }
                    break;
                case 4:
                    if (strcmp(token, "YES") == 0) {
                        h->is_elevator = YES;
                    } else if (strcmp(token, "NO") == 0) {
                        h->is_elevator = NO;
                    } else {
                        fprintf(stderr, "Invalid elevator value at line %d: %s\n", line_count, token);
                        free(h);
                        if (file_name != NULL) fclose(file_ptr);
                        return 1;
                    }
                    break;
                case 5:
                    if (strcmp(token, "YES") == 0) {
                        h->is_chute = YES;
                    } else if (strcmp(token, "NO") == 0) {
                        h->is_chute = NO;
                    } else {
                        fprintf(stderr, "Invalid chute value at line %d: %s\n", line_count, token);
                        free(h);
                        if (file_name) fclose(file_ptr);
                        return 1;
                    }
                    break;
                case 6:
                    h->apartment_count = (unsigned int)atoi(token);
                    if (h->apartment_count == 0) { 
                        fprintf(stderr, "Invalid apartment count value at line %d: %s\n", line_count, token);
                        free(h);
                        if (file_name != NULL) fclose(file_ptr);
                        return 1;
                    }
                    break;
                case 7:
                    h->floor_count = (unsigned int)atoi(token);
                    if (h->floor_count == 0) { 
                        fprintf(stderr, "Invalid floor count value at line %d: %s\n", line_count, token);
                        free(h);
                        if (file_name != NULL) fclose(file_ptr);
                        return 1;
                    }
                    break;
                case 8:
                    h->avg_area = (float)atof(token);
                    if (h->avg_area <= EPS) { 
                        fprintf(stderr, "Invalid average area value at line %d: %s\n", line_count, token);
                        free(h);
                        if (file_name != NULL) fclose(file_ptr);
                        return 1;
                    }
                    break;
                default:
                    fprintf(stderr, "Too many fields\n");
                    free(h);
                    if (file_name) fclose(file_ptr);
                    return 1;
            }
            field++;
            token = strtok(NULL, ",");
        }
        if (field != 9) {
            fprintf(stderr, "Too few fields\n");
            free(h);
            if (file_name) fclose(file_ptr);
            return 1;
        }
        deque_push_back(deque, h);
        }
        if (ferror(file_ptr)) {
            fprintf(stderr, "Error reading file\n");
            if (file_name) fclose(file_ptr);
            return 1;
        }
    
        if (file_name) {
            fclose(file_ptr);
        }
        return 0;
}

int write_csv(const char* file_name, deque* deque) {
    FILE* file_ptr = stdout;
    if (file_name) {
        file_ptr = fopen(file_name, "w");
        if (file_ptr == NULL) {
            fprintf(stderr, "Cannot create file\n");
            return 1;
        }
    }
    size_t size = deque_get_size(deque);
    for (size_t i = 0; i < size; i++) {
        house* h = (house*)deque_get_elem(deque, i);
        if (h == NULL) {
            fprintf(stderr, "Element at index %zu points to NULL\n", i);
            if (file_name) fclose(file_ptr);
            return 1;
        }
        const char* type_str;
        switch (h->type) {
            case PANEL: 
                type_str = "PANEL"; 
                break;
            case BRICK: 
                type_str = "BRICK"; 
                break;
            case MONO:  
                type_str = "MONO"; 
                break;
            default:    
                type_str = "UNKNOWN";
        }
        const char* elevator_str;
        if (h->is_elevator == YES) {
            elevator_str = "YES";
        } else {
            elevator_str = "NO";
        }
        const char* chute_str;  
        if (h->is_chute == YES) {
            chute_str = "YES";
        } else {
            chute_str = "NO";
        }
        fprintf(file_ptr, "%s,%s,%s,%u,%s,%s,%u,%u,%.2f\n", h->builder, h->district, type_str, h->year, elevator_str, chute_str,
             h->apartment_count, h->floor_count, h->avg_area);
    }
    if (file_name) {
        fclose(file_ptr);
    }
    return 0;
}

int print_table(const char* file_name, deque* d) {
    FILE* file_ptr = stdout;
    if (file_name) {
        file_ptr = fopen(file_name, "w");
        if (file_ptr == NULL) {
            fprintf(stderr, "Cannot create file\n");
            return 1;
        }
    }
    size_t size = deque_get_size(d);
    if (size == 0) {
        fprintf(file_ptr, "Nothing to print\n");
        if (file_name) fclose(file_ptr);
        return 0;
    }
    fprintf(file_ptr, "Builder District Type Year Elev Chute Apart Floors Area\n");
    for (size_t i = 0; i < size; i++) {
        house* h = deque_get_elem(d, i);
        if (h == NULL) continue;
        const char* type_str;
        switch (h->type) {
            case PANEL: 
                type_str = "PANEL"; 
                break;
            case BRICK: 
                type_str = "BRICK"; 
                break;
            case MONO:  
                type_str = "MONO"; 
                break;
            default:    
                type_str = "-";
        }
        const char* elevator_str;
        if (h->is_elevator == YES) {
            elevator_str = "YES";
        } else {
            elevator_str = "NO";
        }
        const char* chute_str;  
        if (h->is_chute == YES) {
            chute_str = "YES";
        } else {
            chute_str = "NO";
        }
        fprintf(file_ptr, "%s %s %s %u %s %s %u %u %.2f\n", h->builder, h->district, type_str, h->year, 
            elevator_str, chute_str, h->apartment_count, h->floor_count, h->avg_area);
    }
    if (ferror(file_ptr)) {
        fprintf(stderr, "Error reading file\n");
        if (file_name) fclose(file_ptr);
        return 1;
    }
    if (file_name) {
        fclose(file_ptr);
    }
    return 0;
}



