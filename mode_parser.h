#ifndef MODE_PARSER_H__
#define MODE_PARSER_H__

#include <stdio.h>
#include <string.h>
#include "square_solver.h"
#include "square_unit_test.h"

void parse_mode(const char programm_name[], const char mode[]);

void wrong_flag(const char programm_name[], const char wrong_mode[]);
void solve_from_terminal();
void print_version();


#endif // MODE_PARSER_H__
