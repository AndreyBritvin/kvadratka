#ifndef COLOR_OUTPUT_H_
#define COLOR_OUTPUT_H_

#include <stdio.h>
#include <stdarg.h>

enum color
{
    RED
};

void print_color(int color, const char * format, ...);

#endif // COLOR_OUTPUT_H_
