#ifndef SQUARE_UNIT_TEST_H
#define SQUARE_UNIT_TEST_H

#include "square_solver.h"


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

int run_test(unsigned int test_id, struct unit_test_input);

int run_all_tests(struct unit_test_input [], unsigned int MAX_TEST_COUNT);

#endif // SQUARE_UNIT_TEST_H
