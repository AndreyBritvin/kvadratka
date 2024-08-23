/**
 * @file square_unit_test.h
 * @author Andrey Britvin
 * @brief
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

/**
 * @brief
 *
 * @param test_id
 * @return int
 */
int run_test(unsigned int test_id, struct unit_test_input);

/**
 * @brief
 *
 * @param MAX_TEST_COUNT
 * @return int
 */
int run_all_tests(struct unit_test_input [], unsigned int MAX_TEST_COUNT);

#endif // SQUARE_UNIT_TEST_H
