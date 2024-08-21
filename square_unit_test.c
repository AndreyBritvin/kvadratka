#include "square_unit_test.h"

struct unit_test_input all_tests[] =
{
    {{0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}},
    {{0, 0, 0}, {0, 0, 0}},
};

int run_test(int test_id, struct unit_test_input input)
{
    double x1 = 0, x2 = 0;

    printf("%lg, %lg\n", input.expected_solution.x1, input.expected_solution.x2);
    set_minimum_solution(&input.expected_solution.x1, &input.expected_solution.x2);
    printf("%lg, %lg\n", input.expected_solution.x1, input.expected_solution.x2);

    //solve_equation();

    return 0;
}

int run_all_tests()
{
    for (int test_id = 0; test_id < sizeof(all_tests) / sizeof(struct unit_test_input); test_id++)
    {
        run_test(test_id, all_tests[test_id]);
    }
    return 0;
}


















