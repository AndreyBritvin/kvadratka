#ifndef MY_ASSERT_H_
#define MY_ASSERT_H_

#include "color_output.h"

#define MY_ASSERT(EXPR); {((EXPR)) ?  (void(0)) :\
                          print_color(RED, "ERROR in %s line %d (function %s):"\
                           "Assert "#EXPR" failed\n", __FILE__, __LINE__, __func__); }

#endif // MY_ASSERT_H_
