#include "double_procedures.h"

_Bool compare_equal_double(double d1, double d2)
{
    return (fabs(d1 - d2) < EPSILON) ? 1 : 0;
}

void set_minimum_solution(double *solution_x1, double *solution_x2)
{
    assert(solution_x1!=solution_x2);
    assert(solution_x1!=NULL);
    assert(solution_x2!=NULL);

    if (*solution_x1>*solution_x2)
    {
        double temp_x = *solution_x1;
        *solution_x1 = *solution_x2;
        *solution_x2 = temp_x;
    }
}
