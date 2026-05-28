#ifndef ERRORS_H
#define ERRORS_H

typedef enum 
{
    operation_ok = 0,
    memory_allocation_failed = 10,
    polynomial_not_defined = 20,
    operation_not_defined = 21,
    incompatible_types = 30,
    invalid_type = 31
} polynomial_errors_t;

typedef enum 
{
    number_is_ok = 0,
    number_is_out_of_range = 10,
    number_is_incorrect = 20,
    number_is_empty = 21,
    number_has_extra_chars = 22
} number_errors_t;

#endif