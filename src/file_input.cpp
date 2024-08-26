#include "file_input.h"



int open_file(FILE **fp, const char filename[])
{
    MY_ASSERT(fp != NULL);
    MY_ASSERT(filename != NULL);

    if ((*fp = fopen(filename, "r")) == NULL)
    {
        fprintf(stderr, "Error in opening file: %s\n", filename);

        return errno;
    }

    return FILE_SUCCESS;
}


int close_file(FILE **fp, const char filename[])
{
    MY_ASSERT(fp != NULL);
    MY_ASSERT(filename != NULL);

    if (fclose(*fp))
    {
        fprintf(stderr, "Error in closing file: %s", filename);

        return errno;
    }

    return FILE_SUCCESS;
}

unsigned int file_unit_test_output(FILE **fp, struct unit_test_input test_input[])
{
    MY_ASSERT(fp != NULL);
    MY_ASSERT(test_input != NULL);


    unsigned int test_count = 0;

    struct unit_test_input str_to_app = {{0, 0, 0}, {0, 0, 0}}; // struct to append

    //temp vars to avoid half_structure errors
    double temp_a = 0, temp_b = 0, temp_c = 0, temp_x1 = 0, temp_x2 = 0;
    int temp_n_roots = 0;

    int ret = 0;

    //                  a   b   c   nR  x1  x2
    while ((ret = fscanf(*fp, "%lf %lf %lf %d %lf %lf\n",             \
                    &temp_a, &temp_b, &temp_c,                        \
                    &temp_n_roots, &temp_x1, &temp_x2                 \
                    )) != EOF && ret == 6)

    {
        str_to_app.coefficients.a = temp_a;
        str_to_app.coefficients.b = temp_b;
        str_to_app.coefficients.c = temp_c;

        str_to_app.expected_solution.x1 =      temp_x1;
        str_to_app.expected_solution.x2 =      temp_x2;
        str_to_app.expected_solution.n_roots = temp_n_roots;


        test_input[test_count] = str_to_app;

        str_to_app = {};

        test_count++;
    }

    if (ret != EOF && ret != 6)
    {
        print_error("Smth wrong in input data test #%u, ret = %d\n"                 \
                    "All tests before scanned success\n", test_count, ret);
    }

    return test_count;
}
