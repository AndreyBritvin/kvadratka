#include "square_unit_test.h"


int run_test(unsigned int test_id, struct unit_test_input input)
{
    struct solution sol_to_check = {0, 0, 0};

    solve_equation(input.coefficients, &sol_to_check);

    set_minimum_solution(&input.expected_solution.x1, &input.expected_solution.x2);
    set_minimum_solution(&sol_to_check.x1,            &sol_to_check.x2           );


    if (input.expected_solution.n_roots != sol_to_check.n_roots
        || !compare_equal_double(input.expected_solution.x1, sol_to_check.x1)
        || !compare_equal_double(input.expected_solution.x1, sol_to_check.x1))
    {
        printf("---------------------------------------------------------------\n"
               "! ERROR in Test #%u: a=%lg b=%lg c=%lg n_roots=%d x1=%lg x2=%lg\n"
               "! Expected values: n_roots=%d x1=%lg x2=%lg\n"
               "---------------------------------------------------------------\n",
               test_id, input.coefficients.a, input.coefficients.b, input.coefficients.c,
               sol_to_check.n_roots, sol_to_check.x1, sol_to_check.x2,
               input.expected_solution.n_roots, input.expected_solution.x1, input.expected_solution.x2);

        return SOLUTION_INCORRECT;
    }

    return SOLUTION_CORRECT;
}

int run_all_tests(struct unit_test_input tests[], unsigned int MAX_TEST_COUNT)
{
    int count_unsuccess = 0;

    for (unsigned int test_id = 0; test_id < MAX_TEST_COUNT; test_id++)
    {
        count_unsuccess += run_test(test_id + 1, tests[test_id]);
    }

    return count_unsuccess;
}


















