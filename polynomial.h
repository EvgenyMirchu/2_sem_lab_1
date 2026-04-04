#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include "type_info.h"
#include "errors.h"
#include "integer.h"
#include "complex.h"

typedef struct polynomial;

polynomial_t* polynomial_create(type_info_t* type, void* size, polynomial_errors_t* operation_result);
polynomial_t* polynomial_summarize(const polynomial_t* polynomial_1, const polynomial_t* polynomial_2, polynomial_errors_t* operation_result);
polynomial_t* polynomial_multiply_by_polynomial(const polynomial_t* polynomial_1, const polynomial_t* polynomial_2, polynomial_errors_t* operation_result);
polynomial_t* polynomial_multiply_by_const(const polynomial_t* polynomial, const void* const, polynomial_errors_t* operation_result);
void* polynomial_get_value(const polynomial_t* polynomial, void* x, polynomial_errors_t* operation_result);
int polynomial_delete(polynomial_t* polynomial, polynomial_errors_t* operation_result);

#endif