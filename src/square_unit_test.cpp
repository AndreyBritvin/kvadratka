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
        print_color(RED,
               "---------------------------------------------------------------\n"
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
        if (run_test(test_id + 1, tests[test_id]))
        {
            count_unsuccess++;
        }
        else
        {
            print_color(GREEN, "Test #%u passed\n", test_id + 1);
        }
    }

    return count_unsuccess;
}


void file_tests_result(const char filename[])
{
    #ifndef PROGRAMM_UNIT_TEST

    FILE *file_ptr = NULL; // File to unit test data

    struct unit_test_input to_test[MAX_UNIT_TEST_COUNT] = {};

    if (int error_num = open_file(&file_ptr, filename))
    {
        printf("Error: %s\n", strerror(error_num));

        exit(EXIT_FAILURE);
    }

    unsigned int TEST_COUNT = file_unit_test_output(&file_ptr, to_test);

    if (int error_num = close_file(&file_ptr, filename))
    {
        printf("Error: %s\n", strerror(error_num));

        exit(EXIT_FAILURE);
    }

    printf("Неверно пройденных тестов: %d/%u\n", run_all_tests(to_test, TEST_COUNT), TEST_COUNT);

    #else // PROGRAMM_UNIT_TEST

    size_t MAX_TEST_COUNT = sizeof(all_tests) / sizeof(struct unit_test_input);
    printf("Неверно пройденных тестов: %d/%u\n", run_all_tests(all_test, TEST_COUNT), TEST_COUNT);

    #endif // PROGRAMM_UNIT_TEST

}
















