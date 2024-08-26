#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#include "mode_parser.h"

int main(const int argc, const char *argv[])
{
    if (argc == 1)
    {
        printf("Для помощи введите: %s -h\n\n", argv[0]);
        parse_mode(argv[0], "-s", 1, argc);
    }

    for (int arg_num = 1; arg_num < argc; arg_num++)
    {
        parse_mode(argv[0], argv[arg_num], arg_num + 1, argc);
    }

    return 0;
}
