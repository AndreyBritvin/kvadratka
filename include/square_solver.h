/**
 * @file square_solver.h
 * @author Andrey Britvin
 * @brief
 * @version 1.0
 * @date 2024-08-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SQUARE_SOLVER_H
#define SQUARE_SOLVER_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include <math.h>

#include "double_procedures.h"

#include "my_assert.h"

/**
 * @brief
 *
 */
enum number_of_roots
{
    INF_ROOTS  = -1,
    ZERO_ROOTS =  0,
    ONE_ROOT   =  1,
    TWO_ROOTS  =  2,
};

/**
 * @brief
 *
 */
struct solution
{
    int n_roots;
    double x1;
    double x2;
};

/**
 * @brief
 *
 */
struct coefficient
{
    double a;
    double b;
    double c;
};

/**
 * @brief Печать приветствия пользователю
 */
void print_greeting();

/**
 * @brief Получение значений трёх коэффициентов в структуре
 *
 * @param coef структура, в которую необходимо считать коэффициенты
 */
void get_coefficients(struct coefficient *coef);

/**
 * @brief Решает квадратное уравнение
 *
 * @param coef
 * @param sol
 */
void solve_quadratic_equation(const struct coefficient coef, struct solution *sol);

/**
 * @brief
 *
 * @param coef
 * @param sol
 */
void solve_linear_equation(const struct coefficient coef, struct solution *sol);

/**
 * @brief
 *
 * @param coef
 * @param sol
 */
void solve_equation(const struct coefficient coef, struct solution *sol);

/**
 * @brief
 *
 * @param coef
 * @param sol
 */
void print_solution(const struct coefficient coef, const struct solution sol);

/**
 * @brief
 *
 * @param print_buf
 */
void clear_buffer(_Bool print_buf);

#endif // SQUARE_SOLVER_H
