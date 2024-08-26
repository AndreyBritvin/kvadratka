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
#include <errno.h>
#include "square_unit_test.h"
#include "my_macros.h"

enum file_status
{
    FILE_SUCCESS,
    FILE_UNSUCCESS,
};

/**
 * @brief Открывает файл и возвращает статус открытия
 *
 * @param[out] fp Указатель на файл
 * @param[in] filename Имя файла
 * @return int FILE_SUCCESS, если всё ОК
 *             errno, если возникла ошибка
 */
int open_file(FILE **fp, const char filename[]);

/**
 * @brief Закрывает файл и возвращает статус закрытия
 *
 * @param[out] fp Указатель на файл
 * @param[in] filename Имя файла
 * @return int FILE_SUCCESS, если всё ОК
 *             errno, если возникла ошибка
 */
int close_file(FILE **fp, const char filename[]);

/**
 * @brief Записывает в массив структур данные из файла для unit теста
 *
 * @param[out] fp Указатель на файловый указатель
 * @param[in] test_input Массив структур, в который необходимо ввести данные
 *
 * @return unsigned int Количество тестов которые необходимо пройти
 */
unsigned int file_unit_test_output(FILE **fp, struct unit_test_input test_input[]);


#endif // FILE_INPUT_H_
