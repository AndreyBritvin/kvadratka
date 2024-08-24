#include "file_input.h"



int open_file(FILE **fp, const char filename[])
{
    MY_ASSERT(fp != NULL);
    MY_ASSERT(filename != NULL);

    if ((*fp = fopen(filename, "r")) == NULL)
    {
        fprintf(stderr, "Error in opening file: %s\n", filename);

        return FILE_UNSUCCESS;
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

        return FILE_UNSUCCESS;
    }

    return FILE_SUCCESS;
}

unsigned int file_unit_test_output(FILE **fp, struct unit_test_input test_input[])
{
    MY_ASSERT(fp != NULL);
    MY_ASSERT(test_input != NULL);


    unsigned int test_count = 0;

    struct unit_test_input str_to_app = {{0, 0, 0}, {0, 0, 0}}; // struct to append

    //                  a   b   c   nR  x1  x2
    while (fscanf(*fp, "%lf %lf %lf %d %lf %lf",             \
                    &str_to_app.coefficients.a,              \
                    &str_to_app.coefficients.b,              \
                    &str_to_app.coefficients.c,              \
                    &str_to_app.expected_solution.n_roots,   \
                    &str_to_app.expected_solution.x1,        \
                    &str_to_app.expected_solution.x2         \
                    ) != EOF)

    {
        test_input[test_count] = str_to_app;

        str_to_app = {};

        test_count++;
    }

    return test_count;
}
