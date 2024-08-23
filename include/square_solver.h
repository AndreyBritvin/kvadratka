/**
 * @file square_solver.h
 * @author Andrey Britvin
 * @brief Решение уравнения
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

#include "my_macros.h"

/**
 * @brief Число корней
 *
 */
enum number_of_roots
{
    INF_ROOTS  = -1,
    ZERO_ROOTS =  0,
    ONE_ROOT   =  1,
    TWO_ROOTS  =  2,
};

struct solution
{
    int n_roots;
    double x1;
    double x2;
};

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
 * @brief Решение квадратное уравнение
 *
 * @param coef Структура с коэффициентами
 * @param sol Структура, куда будет записано решение
 *
 * @warning Если coef.a == 0 или некорректный ввод (inf или nan), то сработает assert
 */
void solve_quadratic_equation(const struct coefficient coef, struct solution *sol);

/**
 * @brief Решает линейное уравнение, когда coef.a == 0
 *
 * @param coef Структура с коэффициентами уравнения
 * @param sol Структура, куда будет записано решение
 */
void solve_linear_equation(const struct coefficient coef, struct solution *sol);

/**
 * @brief Функция, которая определяет тип уравнения и решает его
 *
 * @param coef Структура с коэффициентами уравнения
 * @param sol Структура, куда будет записано решение
 */
void solve_equation(const struct coefficient coef, struct solution *sol);

/**
 * @brief Функция, которая печатает ответ в зависимости от получившегося результата
 *
 * @param coef Структура с коэффициентами уравнения
 * @param sol Структура с решённым уравнением
 */
void print_solution(const struct coefficient coef, const struct solution sol);

/**
 * @brief Функция очистки буффера stdin
 *
 * @param print_buf true = напечатать содержимое буффера stdin
 *                 false = уничтожить безвовзратно
 */
void clear_buffer(bool print_buf);

#endif // SQUARE_SOLVER_H
