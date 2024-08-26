/**
 * @file color_output.h
 * @author Andrey Britvin
 * @brief Собственный цветной ввод вывод
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

#define RED_COLOR "\033[0;31m"
#define GREEN_COLOR "\033[0;32m"
#define RESET_COLOR "\033[0m"

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
 * @param[in] color Номер цвета (color)
 * @param[in] format Строка для printf
 * @param[in] ... Переменные для printf
 *
 * @return То же самое, что возвращает printf
 */
int print_color(int color, const char * format, ...);

/**
 * @brief Устанаваливает цвет консоли в зависимости от аргумента (color)
 *
 * @param[in] color Номер цвета
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
