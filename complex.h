#ifndef COMPLEX_H
#define COMPLEX_H

#include "type_info.h"

typedef struct
{
    int Re;
    int Im;
} complex_t;


void complex_summarize(const void* complex_arg_1, const void* complex_arg_2, void* result);
void complex_multiply(const void* complex_arg_1, const void* complex_arg_2, void* result);
int complex_get_Re(const void* complex_arg);
int complex_get_Im(const void* complex_arg);
void complex_print(const void* data);
//type_info_t* get_complex_type_info();

#endif 