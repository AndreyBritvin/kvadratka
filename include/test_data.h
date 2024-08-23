/**
 * @file test_data.h
 * @author Andrey Britvin
 * @brief Тестовые данные для unit теста solve_equation
 * @version 1.0
 * @date 2024-08-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef TEST_DATA_H___
#define TEST_DATA_H___

#include "square_solver.h"
#include "square_unit_test.h"

/**
 * @brief Тестовые данные из структуры коэффициентов и решения
 *
 */
static struct unit_test_input all_tests[] =
{
    //a, b, c                 n_roots,   x1,      x2
    {{   0,    0,          0},    {INF_ROOTS ,  0,       0}},
    {{   0,    0, 3.14159265},    {ZERO_ROOTS,  0,       0}},
    {{   0,    5,       -2.5},    {ONE_ROOT  ,0.5,     0.5}},
    {{ 2.5,    0,        -10},    {TWO_ROOTS , -2,       2}},
    {{   0, -432,          0},    {ONE_ROOT  ,  0,       0}},
    {{3.34,    0,          0},    {ONE_ROOT  ,  0,       0}},
    {{-5.6, 8.23,          0},    {TWO_ROOTS ,  0, 1.46964}},
    {{   1,    2,          1},    {ONE_ROOT  , -1,      -1}},
};

#endif // TEST_DATA_H___
