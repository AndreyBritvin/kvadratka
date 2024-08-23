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

/**
 * @brief Custom assert function
 *
 */

#define MY_ASSERT(EXPR); { if (!(EXPR))\
                            {\
                            fprintf(stderr, "\033[0;31m"\
                                    "ERROR in %s line: %d (function %s):\n"\
                                    "Assertion "#EXPR" failed\n\n" "\033[0m", \
                                    __FILE__, __LINE__, __func__);\
                                    exit(EXIT_FAILURE);\
                            }\
                         }


#endif // MY_ASSERT_H_
