#include "color_output.h"

// vprintf, vargs

void print_color(int color, const char * format, ...)
{
    va_list args;
    va_start (args, format);

    set_color(color);

    vprintf(format, args);
    reset_color();

    va_end (args);
}

void set_color(int color)
{
    switch (color)
    {
        case RED:
        {
            set_red_color();
            break;
        }

        default:
        {
            reset_color();
            break;
        }
    }
}

void reset_color()
{
    printf("\033[0m");
}

void set_red_color()
{
    printf("\033[0;31m");
}

void set_green_color()
{
    printf("\033[0;32m");
}
