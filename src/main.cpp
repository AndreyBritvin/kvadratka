#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#include "mode_parser.h"

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        wrong_flag(argv[0], "");
    }

    for (int arg_num = 1; arg_num < argc; arg_num++)
    {
        parse_mode(argv[0], argv[arg_num], arg_num - 1, argc);
    }

    return 0;
}
