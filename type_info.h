#ifndef TYPE_INFO_H
#define TYPE_INFO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Букалинский вариант (чет не зашел)

// typedef void (*binary_operation)(const void* arg1, const void* arg2, void* result);

// typedef struct 
// {
//     size_t size;
//     void (*summarize)(const void*, const void*, void*);
//     void (*multiply)(const void*, const void*, void*);;
//     void (*print)(const void*);
// } type_info_t;

typedef enum type_info 
{
    type_int = 0,
    type_complex = 1
} type_info_t;

//А это вариант из Хабра: https://habr.com/ru/articles/568588/
#endif