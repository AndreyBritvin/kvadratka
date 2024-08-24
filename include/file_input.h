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

enum file_status
{
    FILE_SUCCESS,
    FILE_UNSUCCESS,
};

int open_file(FILE *fp, char filename[]);
int close_file(FILE *fp,  char filename[]);

char * read_line(FILE *fp);

#endif // FILE_INPUT_H_
