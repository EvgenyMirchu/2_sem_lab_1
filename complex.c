#include "complex.h"

//static type_info_t* complex_type_info = NULL;

void complex_summarize(const void* complex_arg_1, const void* complex_arg_2, void* result)
{
    complex_t* complex_1 = (complex_t*)complex_arg_1;
    complex_t* complex_2 = (complex_t*)complex_arg_2;
    complex_t* res = (complex_t*)result;
    
    res->Re = complex_1->Re + complex_2->Re;
    res->Im = complex_1->Im + complex_2->Im;
}

void complex_multiply(const void* complex_arg_1, const void* complex_arg_2, void* result)
{
    complex_t* complex_1 = (complex_t*)complex_arg_1;
    complex_t* complex_2 = (complex_t*)complex_arg_2;
    complex_t* res = (complex_t*)result;

    int a = complex_1->Re, b = complex_1->Im; 
    int c = complex_2->Re, d = complex_2->Im;
    //(a + i*b)(c + i*d) = a*c - b*d + i*(a*d + b*c)
    res->Re = a*c - b*d;
    res->Im = a*d + b*c;
}

void complex_print(const void* complex_arg)
{
    complex_t* complex = (complex_t*)complex_arg;
    printf("(%d, %d)", complex->Re, complex->Im);
}

// type_info_t* get_complex_type_info()
// {
//     if (complex_type_info == NULL) 
//     {
//         complex_type_info = (type_info_t*)malloc(sizeof(type_info_t));
//         complex_type_info->size = sizeof(int);
//         complex_type_info->summarize = complex_summarize;
//         complex_type_info->multiply = complex_multiply;
//         complex_type_info->print = complex_print;
//     }

//     return complex_type_info;
// }