#ifndef TYPE_INFO_H
#define TYPE_INFO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void (*binary_operation)(const void* arg1, const void* arg2, void* result);

typedef struct 
{
    size_t size;
    binary_operation summarize;
    binary_operation multiply;
    void (*print)(const void*);
} type_info_t;

#endif