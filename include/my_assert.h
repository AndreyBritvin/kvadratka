#ifndef MY_ASSERT_H_
#define MY_ASSERT_H_

#include <stdio.h>

#define MY_ASSERT(EXPR); {((EXPR)) ?  true :\
                          fprintf(stderr, "\033[0;31m"\
                            "ERROR in %s line: %d (function %s):\n"\
                            "Assertion "#EXPR" failed\n\n" "\033[0m", \
                            __FILE__, __LINE__, __func__); }


#endif // MY_ASSERT_H_
