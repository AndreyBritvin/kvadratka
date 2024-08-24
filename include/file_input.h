/**
 * @file file_input.h
 * @author Andrey Britvin
 * @brief Работа с файловым вводом выводом
 * @version 1.0
 * @date 2024-08-24
 *
 * @copyright Copyright (c) 2024
 *
 */


#ifndef FILE_INPUT_H_
#define FILE_INPUT_H_

#include <stdio.h>
#include "square_unit_test.h"

enum file_status
{
    FILE_SUCCESS,
    FILE_UNSUCCESS,
};

int open_file(FILE **fp, char filename[]);
int close_file(FILE **fp,  char filename[]);

int file_unit_test_output(FILE **fp, struct unit_test_input test_input[]);

char * read_line(FILE *fp);

#endif // FILE_INPUT_H_
