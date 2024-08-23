/**
 * @file double_procedures.h
 * @author Andrey Britvin
 * @brief
 * @version 1.0
 * @date 2024-08-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef DOUBLE_PROCEDURES_H
#define DOUBLE_PROCEDURES_H

#include <stdbool.h>
#include <math.h>
#include "my_assert.h"

/**
 * @brief
 *
 * @param d1
 * @param d2
 * @return _Bool
 */
_Bool compare_equal_double(double d1, double d2);

/**
 * @brief Set the minimum solution object
 *
 * @param solution_x1
 * @param solution_x2
 */
void set_minimum_solution(double *solution_x1, double *solution_x2);


#endif // DOUBLE_PROCEDURES_H
