#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include "type_info.h"
#include "errors.h"
#include "integer.h"
#include "complex.h"
#include <limits.h>
#include <stddef.h>  
#include <stdlib.h>  
#define MAX_DEGREE 15
//#define INT_MAX

typedef struct polynomial polynomial_t;

polynomial_t* polynomial_create(type_info_t* type, void* size, polynomial_errors_t* operation_result);
polynomial_t* polynomial_summarize(const polynomial_t* polynomial_1, const polynomial_t* polynomial_2, polynomial_errors_t* operation_result);
polynomial_t* polynomial_multiply_by_polynomial(const polynomial_t* polynomial_1, const polynomial_t* polynomial_2, polynomial_errors_t* operation_result);
polynomial_t* polynomial_multiply_by_number(const polynomial_t* polynomial, const void* const, polynomial_errors_t* operation_result);
void* polynomial_get_value(const polynomial_t* polynomial, void* x, polynomial_errors_t* operation_result);
int polynomial_delete(polynomial_t* polynomial, polynomial_errors_t* operation_result);


size_t polynomial_get_size(const polynomial_t* polynomial);
void* polynomial_get_start(const polynomial_t* polynomial);
type_info_t* polynomial_get_type(const polynomial_t* polynomial);
size_t polynomial_get_number_of_elements(const polynomial_t* polynomial);


polynomial_t* polynomial_set_coefficient(const polynomial_t* polynomial, const void* changing_degree, const void* coefficient, polynomial_errors_t* operation_result);
polynomial_t* polynomial_set_to_null(const polynomial_t* polynomial, polynomial_errors_t* operation_result);
polynomial_t* polynomial_set_different_type(const polynomial_t* polynomial, polynomial_errors_t* operation_result);

#endif