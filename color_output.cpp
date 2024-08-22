#include "color_output.h"

// vprintf, vargs

void print_color(int color, const char * format, ...)
{
    va_list args;
    va_start (args, format);

    printf("\033[0m");
    vprintf(format, args);
    printf("\033[0m");

    va_end (args);
}
