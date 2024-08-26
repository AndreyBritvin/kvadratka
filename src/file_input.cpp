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

    int ret = 0;

    //                  a   b   c   nR  x1  x2
    while ((ret = fscanf(*fp, "%lf %lf %lf %d %lf %lf\n",             \
                    &str_to_app.coefficients.a,              \
                    &str_to_app.coefficients.b,              \
                    &str_to_app.coefficients.c,              \
                    &str_to_app.expected_solution.n_roots,   \
                    &str_to_app.expected_solution.x1,        \
                    &str_to_app.expected_solution.x2         \
                    )) != EOF && ret == 6)

    {
        test_input[test_count] = str_to_app;

        str_to_app = {};

        test_count++;
    }

    if (ret != EOF && ret != 6)
    {
        fprintf(stderr, "Smth wrong in input data test #%u, ret = %d\n"
                        "All tests before scanned success\n", test_count, ret);
    }

    return test_count;
}
