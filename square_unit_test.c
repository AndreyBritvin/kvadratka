#include "square_unit_test.h"

int run_test(struct unit_test_input input)
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

    run_test();
    return 0;
}


















