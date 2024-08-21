#include "square_solver.h"

#ifndef SQUARE_UNIT_TEST_H
#define SQUARE_UNIT_TEST_H

struct test_input
{
    int test_num;
    struct coefficient coefficients;
    struct solution expected_solution;
};

int run_test(struct test_input);

int run_all_tests();

#endif // SQUARE_UNIT_TEST_H
