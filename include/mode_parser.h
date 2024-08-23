/**
 * @file mode_parser.h
 * @author Andrey Britvin
 * @brief
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

bool cmp_str_to_multiple(const char *first_str_to_cmp, const char *str1, const char *str2);

void parse_mode(const char programm_name[], const char mode[]);

void wrong_flag(const char programm_name[], const char wrong_mode[]);
void solve_from_terminal();
void version();
void tests_result();
void help();


#endif // MODE_PARSER_H__
