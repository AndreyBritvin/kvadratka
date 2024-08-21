#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "square_solver.h"
#include "square_unit_test.h"

#include <math.h>



int main()
{
    printf("Неверно пройденных тестов: %d\n", run_all_tests());

    print_greeting();

    int is_quit = 0;
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

        clear_buffer(false);
    }
    while(is_quit != EOF);

    return 0;
}
