/**
 * @file my_assert.h
 * @author Andrey Britvin
 * @brief Custom assert function
 * @version 1.0
 * @date 2024-08-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef MY_ASSERT_H_
#define MY_ASSERT_H_

#include <stdio.h>

#define DISABLE_WARNING_PUSH _Pragma("GCC diagnostic push")
#define DISABLE_WARNING_FLOAT_EQUAL   _Pragma("GCC diagnostic ignored \"-Wfloat-equal\"")
#define DISABLE_WARNING_POP _Pragma("GCC diagnostic pop")


/**
 * @brief Custom macros
 *
 */

#define MY_ASSERT(EXPR); { if (!(EXPR))                                         \
                            {                                                   \
                            fprintf(stderr, "\033[0;31m"                        \
                                    "ERROR in %s line: %d (function %s):\n"     \
                                    "Assertion "#EXPR" failed\n\n" "\033[0m",   \
                                    __FILE__, __LINE__, __func__);              \
                                    exit(EXIT_FAILURE);                         \
                            }                                                   \
                         }

/**
 * @brief Тренировка стандарта IEEE754
 *
 */
#define MY_ISNAN_VAR(NUM) ( ((*(unsigned long long *) &(NUM)) << 1 >> 53) == 0x7FF      \
                         && ((*(unsigned long long *) &(NUM)) << 12) != 0               \
                         ? true : false)

/**
 * @brief Тренировка стандарта IEEE754
 *
 */
#define MY_ISFINITE_VAR(NUM) ( ((*(unsigned long long *) &(NUM)) << 1 >> 53) == 0x7FF   \
                            && ((*(unsigned long long *) &(NUM)) << 12) == 0            \
                            ? true : false)


/**
 * @brief Тренировка макросов
 *
 */
#define MY_ISFINITE(NUM) (MY_ISNAN((NUM) * 0) ? false : true)

static bool MY_ISNAN(double NUM);

/**
 * @brief Тренировка макроса ISNAN
 *
 * @warning Предупреждение компилятора выключено намеренно
 */
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wfloat-equal"
#pragma GCC diagnostic ignored "-Wunused-function"
static bool MY_ISNAN(double NUM) {return ((NUM) == (NUM)) ? false : true;}
#pragma GCC diagnostic pop

#endif // MY_ASSERT_H_
