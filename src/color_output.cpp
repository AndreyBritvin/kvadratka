#include "color_output.h"

// vprintf, vargs

int print_color(int color, const char * format, ...)
{
    va_list args;
    va_start (args, format);

    set_color(color);
    int ret_val = vprintf(format, args);
    reset_color();

    va_end (args);

    return ret_val;
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

        case GREEN:
        {
            set_green_color();
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
    printf(RESET_COLOR);
}

void set_red_color()
{
    printf(RED_COLOR);
}

void set_green_color()
{
    printf(GREEN_COLOR);
}
