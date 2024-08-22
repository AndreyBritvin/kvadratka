#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>


#include "mode_parser.h"

int main(int argc, char *argv[])
{
    for (int arg_num = 1; arg_num < argc; arg_num++)
    {
        parse_mode(argv[0], argv[arg_num]);
    }

    return 0;
}
