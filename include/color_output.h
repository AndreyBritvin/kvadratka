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
 * @brief Создание цветов для print_color
 *
 */
enum color
{
    RED,
    GREEN,
};

/**
 * @brief Собственный цветной вывод
 *
 * @param color Номер цвета (color)
 * @param format Строка для printf
 * @param ... Переменные для printf
 */
void print_color(int color, const char * format, ...);

/**
 * @brief Устанаваливает цвет консоли в зависимости от аргумента (color)
 *
 * @param color Номер цвета
 */
void set_color(int color);

/**
 * @brief Устанавливает красный цвет консоли
 *
 */
void set_red_color();

/**
 * @brief Устанавливает зелёный цвет консоли
 *
 */
void set_green_color();

/**
 * @brief Восстанавливает цвет консоли по умолчанию
 *
 */
void reset_color();

#endif // COLOR_OUTPUT_H_
