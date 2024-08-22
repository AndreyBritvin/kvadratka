#ifndef COLOR_OUTPUT_H_
#define COLOR_OUTPUT_H_

#include <stdio.h>
#include <stdarg.h>

enum color
{
    BLACK,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    PURPLE,
    CYAN,
    WHITE,
};

void print_color(int color, const char * format, ...);

void set_color(int color);
void set_red_color();
void set_green_color();
void reset_color();

#endif // COLOR_OUTPUT_H_
