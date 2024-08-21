#include "square_unit_test.h"

struct unit_test_input all_tests[] =
{
    //a,b,c         n_roots, x1, x2
    {{0, 0, 0},             {INF_ROOTS ,  0,       0}},
    {{0, 0, 3.14159265},    {ZERO_ROOTS,  0,       0}},
    {{0, 5, -2.5},          {ONE_ROOT  ,0.5,     0.5}},
    {{2.5, 0, -10},         {TWO_ROOTS , -2,       2}},
    {{0, -432, 0},          {ONE_ROOT  ,  0,       0}},
    {{3.34, 0, 0},          {ONE_ROOT  ,  0,       0}},
    {{-5.6, 8.23, 0},       {TWO_ROOTS ,  0, 1.46964}},
    {{1, 2, 1},             {ONE_ROOT  , -1,      -1}},
};

int run_test(unsigned int test_id, struct unit_test_input input)
{
    struct solution sol_to_check = {0, 0, 0};

    solve_equation(input.coefficients, &sol_to_check);

    set_minimum_solution(&input.expected_solution.x1, &input.expected_solution.x2);
    set_minimum_solution(&sol_to_check.x1,            &sol_to_check.x2           );


    if (input.expected_solution.n_roots != sol_to_check.n_roots ||
        !compare_equal_double(input.expected_solution.x1, sol_to_check.x1) ||
        !compare_equal_double(input.expected_solution.x1, sol_to_check.x1))
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

int run_all_tests()
{
    int count_unsuccess = 0;

    unsigned int MAX_TEST_COUNT = (unsigned int) sizeof(all_tests) / sizeof(struct unit_test_input);

    for (unsigned int test_id = 0; test_id < MAX_TEST_COUNT; test_id++)
    {
        count_unsuccess += run_test(test_id + 1, all_tests[test_id]);
    }
    return count_unsuccess;
}


















