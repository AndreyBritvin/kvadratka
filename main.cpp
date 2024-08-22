#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#include "test_data.h"

#include "mode_parser.h"

int main(int argc, char *argv[])
{
    for (int arg_num = 1; arg_num < argc; arg_num++)
    {
        parse_mode(argv[0], argv[arg_num]);
    }

    unsigned int MAX_TEST_COUNT = (unsigned int) sizeof(all_tests) / sizeof(struct unit_test_input);
    printf("Неверно пройденных тестов: %d\n", run_all_tests(all_tests, MAX_TEST_COUNT));

    return 0;
}
