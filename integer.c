#include "integer.h"

//static type_info_t* int_type_info = NULL;

void int_summarize(const void* int_arg_1, const void* int_arg_2, void* result)
{
    *(int*)result = *(int*)int_arg_1 + *(int*)int_arg_2;
}

void int_multiply(const void* int_arg_1, const void* int_arg_2, void* result)
{
    *(int*)result = *(int*)int_arg_1 * *(int*)int_arg_2;
}

void int_print(const void* data) 
{
    printf("%d", *(int*)data);
}

/* type_info_t* get_int_type_info()
{
    if (int_type_info == NULL) 
    {
        int_type_info = (type_info_t*)malloc(sizeof(type_info_t));
        int_type_info->size = sizeof(int);
        int_type_info->summarize = int_summarize;
        int_type_info->multiply = int_multiply;
        int_type_info->print = int_print;
    }

    return int_type_info;
} */