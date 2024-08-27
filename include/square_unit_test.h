/**
 * @file square_unit_test.h
 * @author Andrey Britvin
 * @brief Unit test для solve_equation()
 * @version 1.0
 * @date 2024-08-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SQUARE_UNIT_TEST_H
#define SQUARE_UNIT_TEST_H

#include "square_solver.h"
#include "color_output.h"
#include <string.h>
#include <stdlib.h>
#include "file_input.h"

struct unit_test_input
{
    struct coefficient coefficients;
    struct solution expected_solution;
};

enum check_status
{
    SOLUTION_CORRECT,
    SOLUTION_INCORRECT,
};

const unsigned int MAX_UNIT_TEST_COUNT = 20;

/**
 * @brief Запускает единичный unit тест
 *
 * @param[in] test_id    Номер теста
 * @param[in] test_input Входные данные для теста
 *
 * @return int SOLUTION_CORRECT   если успешно пройдены тесты,
 *             SOLUTION_INCORRECT если неуспешно
 */
int run_test(unsigned int test_id, struct unit_test_input test_input);

/**
 * @brief Запуск всех тестов
 *
 * @param[in] MAX_TEST_COUNT Количество тестов для запуска
 *
 * @return int Количество неуспешных тестов
 */
int run_all_tests(struct unit_test_input [], unsigned int MAX_TEST_COUNT);

/**
 * @brief Печать информации по результатам теста
 *
 * @param[in] filename Имя файла, откуда будут взяты данные для юнит теста
 */
void file_tests_result(const char filename[]);

#endif // SQUARE_UNIT_TEST_H
