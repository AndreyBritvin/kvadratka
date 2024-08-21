#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "square_solver.h"

#include <math.h>


int main()
{
    print_greeting();

    char is_quit;
    do
    {
        struct coefficient coeffs = {0, 0, 0};
        struct solution sol = {0, 0, 0};

        get_coefficients(&coeffs);
        solve_equation(coeffs, &sol);
        print_solution(coeffs, sol);

        printf("Решить новое уравнение? Введите y для продолжения, n для выхода из программы\n");

        if ((is_quit = getchar()) == 'n')
        {
            break;
        }

        while ((is_quit = getchar()) != '\n')
        {
            continue;
        }
    }
    while(is_quit != EOF);

    return 0;
}
