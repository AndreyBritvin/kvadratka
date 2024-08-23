/**
 * @file double_procedures.h
 * @author Andrey Britvin
 * @brief Операции с числами типа double
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
#include "my_macros.h"

/**
 * @brief Функция сравнения двух чисел типа double с учётом возможных погрешностей
 *
 * @param d1 Первое число для сравнения
 * @param d2 Второе число для сравнения
 * @return bool true, если аргументы равны с точностью до EPSILON
 */
bool compare_equal_double(double d1, double d2);

/**
 * @brief Меняет значения, ставя минимальное в левую позицию, а максимальное - в правую
 *
 * @param solution_x1 Значение, которое должно стать минимальным
 * @param solution_x2 ЗначениеЮ которое должно стать максимальным
 */
void set_minimum_solution(double *solution_x1, double *solution_x2);


#endif // DOUBLE_PROCEDURES_H
