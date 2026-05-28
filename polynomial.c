#include "polynomial.h"


typedef struct polynomial
{
    size_t size;
    size_t number_of_elements;
    void* start;
    type_info_t* type;
} polynomial_t;


polynomial_t* polynomial_create(type_info_t* type, void* number_of_elems, polynomial_errors_t* operation_result)
{
    polynomial_t* polynomial = (polynomial_t*) malloc(sizeof(polynomial_t));
    if (polynomial == NULL)
    {
        *operation_result = memory_allocation_failed;
        return NULL;
    }
    polynomial->number_of_elements = number_of_elems;
    polynomial->type = type;

    switch (*type)
    {
    case type_int:

        void* st = calloc(*(short*) number_of_elems, sizeof(int));
        if (st == NULL)
        {
            *operation_result = memory_allocation_failed;
            return NULL;
        }
        polynomial->size = sizeof(*(short*) number_of_elems * sizeof(int));
        polynomial->start = st;
        *operation_result = operation_ok;
        return polynomial;
    
    case type_complex:
        void* st = calloc(*(short*) number_of_elems, sizeof(complex_t));
        if (st == NULL)
        {
            *operation_result = memory_allocation_failed;
            return NULL;
        }
        polynomial->size = sizeof(*(short*) number_of_elems * sizeof(complex_t));
        polynomial->start = st;
        *operation_result = operation_ok;
        return polynomial;
    }
}

//__________Сложение__________

polynomial_t* polynomial_summarize(const polynomial_t* polynomial_1, const polynomial_t* polynomial_2, polynomial_errors_t* operation_result)
{
    if (polynomial_1 == NULL || polynomial_2 == NULL)
    {
        *operation_result = polynomial_not_defined;
        return NULL;
    } 

    if (polynomial_1->type != polynomial_2->type)
    {
        *operation_result = incompatible_types;
        return NULL;
    }

    polynomial_errors_t* op_res;
    polynomial_t* result = polynomial_create(polynomial_1->type, __max(polynomial_1->size, polynomial_2->size), op_res);

    if (result == NULL)
    {
        *operation_result = *op_res;
        return NULL;
    }

    if (polynomial_1->size >= polynomial_2->size)
    {
        type_info_t* type = polynomial_1->type;
        void* start_1 = polynomial_1->start;
        void* start_2 = polynomial_2->start;
        void* start = result->start;

        switch (*type)
        {
            case type_int:
                int* start_1 = (int*) result->start;
                int* start_2 = (int*) result->start;
                int* start = (int*) result->start;

                for (size_t i = polynomial_2->size - (size_t)1; i >= (size_t)0; i--)
                {
                    int_summarize((const void*) start_1[i], (const void*) start_2[i], (void*) start[i]);
                }

                for (size_t k = 0; k < polynomial_1->size-polynomial_2->size-1; k++)
                {
                    start[k] = start_1[k];
                }
                
                return result;
            
            case type_complex:
                complex_t* start_1 = (int*) result->start;
                complex_t* start_2 = (int*) result->start;
                complex_t* start = (int*) result->start;

                for (size_t i = polynomial_2->size - (size_t)1; i >= (size_t)0; i--)
                {
                    complex_summarize((const void*) start_1[i], (const void*) start_2[i], (void*) start[i]);
                }

                for (size_t k = 0; k < polynomial_1->size-polynomial_2->size-1; k++)
                {
                    start[k] = start_1[k];
                }
                
                return result;
        }
        // for (size_t i = polynomial_2->size-1; i >= (size_t) 0; i--)
        // {
        //     (type_info_t*) start[i] = type->summarize(const void* start_1[i], const void* start_2[i], void* sum_res);
        // }
    }

    else    //  polynomial_1->size < polynomial_2->size
    {
        type_info_t* type = polynomial_1->type;
        void* start_1 = polynomial_1->start;
        void* start_2 = polynomial_2->start;
        void* start = result->start;

        switch (*type)
        {
            case type_int:
                int* start_1 = (int*) result->start;
                int* start_2 = (int*) result->start;
                int* start = (int*) result->start;

                for (size_t i = polynomial_1->size - (size_t)1; i >= (size_t)0; i--)
                {
                    int_summarize((const void*) start_1[i], (const void*) start_2[i], (void*) start[i]);
                }

                for (size_t k = 0; k < polynomial_2->size - polynomial_1->size - 1; k++)
                {
                    start[k] = start_2[k];
                }
                
                return result;
            
            case type_complex:
                complex_t* start_1 = (int*) result->start;
                complex_t* start_2 = (int*) result->start;
                complex_t* start = (int*) result->start;

                for (size_t i = polynomial_1->size - (size_t)1; i >= (size_t)0; i--)
                {
                    complex_summarize((const void*) start_1[i], (const void*) start_2[i], (void*) start[i]);
                }

                for (size_t k = 0; k < polynomial_2->size - polynomial_1->size - 1; k++)
                { 
                    start[k] = start_2[k];
                }
                
                return result;
        }
    }
}

//__________Умножение__________

polynomial_t* polynomial_multiply_by_polynomial(const polynomial_t* polynomial_1, const polynomial_t* polynomial_2, polynomial_errors_t* operation_result)
{
    if (polynomial_1 == NULL || polynomial_2 == NULL)
    {
        *operation_result = polynomial_not_defined;
        return NULL;
    } 

    if (polynomial_1->type != polynomial_2->type)
    {
        *operation_result = incompatible_types;
        return NULL;
    }

    polynomial_errors_t* op_res;
    polynomial_t* result = polynomial_create(polynomial_1->type, polynomial_1->size * polynomial_2->size, op_res);

    if (result == NULL)
    {
        *operation_result = *op_res;
        return NULL;
    }

    type_info_t* type = polynomial_1->type;
    size_t size_1 = polynomial_1->size;
    size_t size_2 = polynomial_2->size;

    switch (*type)
    {
        case type_int:
            int* start_1 = (int*) polynomial_1->start;
            int* start_2 = (int*) polynomial_2->start;
            int* start = (int*) result->start;
            int* product; // произведение

            for (size_t i; i < size_1; i++)
            {
                for (size_t j; j < size_1; j++)
                {
                    int_multiply((const void*) start_1[i], (const void*) start_2[j], (void*) product);
                    int_summarize((const void*) product, (const void*) start[i+j*size_1], (void*) start[i+j*size_1]);
                }
            }
            return result;
            
        case type_complex:
            complex_t* start_1 = (complex_t*) polynomial_1->start;
            complex_t* start_2 = (complex_t*) polynomial_2->start;
            complex_t* start = (complex_t*) result->start;
            complex_t* product; // произведение

            for (size_t i; i < size_1; i++)
            {
                for (size_t j; j < size_1; j++)
                {
                    complex_multiply((const void*) start_1[i], (const void*) start_2[j], (void*) product);
                    complex_summarize((const void*) product, (const void*) start[i+j*size_1], (void*) start[i+j*size_1]);
                }
            }
            return result;
    }
}


polynomial_t* polynomial_multiply_by_number(const polynomial_t* polynomial, const void* number, polynomial_errors_t* operation_result)
{
    if (polynomial == NULL)
    {
        *operation_result = polynomial_not_defined;
        return NULL;
    } 

    polynomial_errors_t* op_res;
    polynomial_t* result = polynomial_create(polynomial->type, polynomial->size, op_res);

    if (result == NULL)
    {
        *operation_result = *op_res;
        return NULL;
    }

    type_info_t* type = polynomial->type;
    size_t size = polynomial->size;

    switch (*type)
    {
    case type_int:
        int* start = (int*) polynomial->start;
        int* res_start = (int*) result->start;

        for (size_t i; i < size; i++)
        {
            int_multiply((const void*) start[i], (const void*) number, (void*) res_start[i]);
        }
        return result;
        
    case type_complex:
        complex_t* start = (complex_t*) polynomial->start;
        complex_t* res_start = (complex_t*) result->start;

        for (size_t i; i < size; i++)
        {
            complex_multiply((const void*) start[i], (const void*) number, (void*) res_start[i]);
        }
        return result;
    }
}


void* polynomial_get_value(const polynomial_t* polynomial, void* x, polynomial_errors_t* operation_result)
{
    if (polynomial == NULL)
    {
        *operation_result = polynomial_not_defined;
        return NULL;
    } 

    type_info_t type = polynomial->type;

    switch (type)
    {
        case type_int:
        int* start = (int*) polynomial->start;
        int* result = 0;
        for (size_t i; i < polynomial->size; i++)
        {
            int_summarize((const void*) result, (const void*) start[i], (void*) result);
        }
        return result;

        case type_complex:
        complex_t* start = (complex_t*) polynomial->start;
        complex_t* result = 0;
        for (size_t i; i < polynomial->size; i++)
        {
            complex_summarize((const void*) result, (const void*) start[i], (void*) result);
        }
        return result;
    }
}

int polynomial_delete(polynomial_t* polynomial, polynomial_errors_t* operation_result)
{
    if (polynomial == NULL)
    {
        *operation_result = polynomial_not_defined;
        return NULL;
    }
    
    free(polynomial);
}

size_t polynomial_get_size(const polynomial_t* polynomial)
{
    if (polynomial != NULL)
    {
        return polynomial->size;
    }
    return 0;
}

void* polynomial_get_start(const polynomial_t* polynomial)
{
    if (polynomial != NULL)
    {
        return polynomial->start;
    }
    return NULL;
}

type_info_t* polynomial_get_type(const polynomial_t* polynomial)
{
    if (polynomial != NULL)
    {
        return &(polynomial->type);
    }
    return NULL;
}

size_t polynomial_get_number_of_elements(const polynomial_t* polynomial)
{
    if (polynomial != NULL)
    {
        return polynomial->number_of_elements;
    }
    return 0;
}

polynomial_t* polynomial_set_coefficient(const polynomial_t* polynomial, const void* changing_degree, const void* coefficient, polynomial_errors_t* operation_result);
polynomial_t* polynomial_set_to_null(const polynomial_t* polynomial, polynomial_errors_t* operation_result);

polynomial_t* polynomial_set_different_type(const polynomial_t* polynomial, polynomial_errors_t* operation_result)
{
    type_info_t* type = polynomial_get_type(polynomial);
    if (type == INT)
    {
        
    }

    else
    {

    }
}