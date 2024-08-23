/**
 * @file mode_parser.h
 * @author Andrey Britvin
 * @brief Обработка различных режимов работы программы через флаги
 * @version 1.0
 * @date 2024-08-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef MODE_PARSER_H__
#define MODE_PARSER_H__

#include <stdio.h>
#include <string.h>
#include "square_solver.h"
#include "square_unit_test.h"
#include "my_assert.h"

/**
 * @brief Функция эквивалентности строки хотя бы одной другой
 *
 * @param first_str_to_cmp Строка, которую надо проверить
 * @param str1 Одно из возможных соответствий
 * @param str2 Второе из возможных соответствий
 * @return true Если str1 или str2 соответствуют first_str_to_cmp
 * @return false Если str1 или str2 НЕ соответствуют first_str_to_cmp
 *
 * @example  cmp_str_to_multiple(flag, "-v", "--version")
 */
bool cmp_str_to_multiple(const char *first_str_to_cmp, const char *str1, const char *str2);

/**
 * @brief Функция выбора режима в зависимости от выбранного флага
 *
 * @param programm_name Имя программы, argv[0]
 * @param mode Флаг, который надо обработать
 */
void parse_mode(const char programm_name[], const char mode[]);

/**
 * @brief Печать информации о неправильном флаге
 *
 * @param programm_name Имя файла argv[0]
 * @param wrong_mode Неправильный флаг, о котором надо сообщить
 */
void wrong_flag(const char programm_name[], const char wrong_mode[]);

/**
 * @brief Решение уравнения из программы
 *
 */
void solve_from_terminal();

/**
 * @brief Печать версии программы
 *
 */
void version();

/**
 * @brief Печать информации по результатам теста
 *
 */
void tests_result();

/**
 * @brief Печать информации при флаге -h или --help
 *
 */
void help();


#endif // MODE_PARSER_H__
