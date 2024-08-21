#include "square_solver.h"

#ifndef SQUARE_UNIT_TEST_H
#define SQUARE_UNIT_TEST_H

struct unit_test_input
{
    struct coefficient coefficients;
    struct solution expected_solution;
};

int run_test(unsigned int test_id, struct unit_test_input);

int run_all_tests();

#endif // SQUARE_UNIT_TEST_H
