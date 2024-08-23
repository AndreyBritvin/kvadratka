/**
 * @file color_output.h
 * @author Andrey Britvin
 * @brief
 * @version 1.0
 * @date 2024-08-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef COLOR_OUTPUT_H_
#define COLOR_OUTPUT_H_

#include <stdio.h>
#include <stdarg.h>

/**
 * @brief
 *
 */
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

/**
 * @brief
 *
 * @param color
 * @param format
 * @param ...
 */
void print_color(int color, const char * format, ...);

/**
 * @brief Set the color object
 *
 * @param color
 */
void set_color(int color);

/**
 * @brief Set the red color object
 *
 */
void set_red_color();

/**
 * @brief Set the green color object
 *
 */
void set_green_color();

/**
 * @brief
 *
 */
void reset_color();

#endif // COLOR_OUTPUT_H_
