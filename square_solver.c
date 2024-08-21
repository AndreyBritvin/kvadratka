#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include "square_solver.h"

void get_coefficients(struct coefficient *coef)
{
    int ch;

    printf("Пожалуйста, введите коэффициенты a, b, c\n");

    int ret = 0;

    while ( (ret = scanf("%lf %lf %lf", &coef->a, &coef->b, &coef->c)) != 3)
    {
        printf("%lg", coef->a);

        while ((ch = getchar()) != '\n')
        {
            printf("%c", ch);
        }
        printf(" не является допустимым вводом. Введите целое или дробное число, например: 1.618 или 3.14\n");
    }

    while ((ch = getchar()) != '\n' && ch != EOF)
    {
            continue;
    }

    return ;
}


void solve_equation(const struct coefficient coef, struct solution *sol)
{
    if (compare_double(coef.a, 0))
    {
        solve_linear_equation(coef, sol);
    }
    else
    {
        solve_quadratic_equation(coef, sol);
    }
}

void solve_quadratic_equation(const struct coefficient coef, struct solution *sol)
{
    double discriminant = coef.b * coef.b - 4 * coef.a * coef.c;

    if (discriminant < 0)
    {
        sol->n_roots = ZERO_ROOTS;

        return ;
    }

    double first_add = (-coef.b) / (2 * coef.a);

    if (compare_double(discriminant, 0))
    {
        sol->n_roots = ONE_ROOT;
        sol->x1 = sol->x2 = first_add;

        return ;
    }

    double second_add = (sqrt(discriminant)) / (2 * coef.a);

    sol->n_roots = TWO_ROOTS;
    sol->x1 = first_add + second_add;
    sol->x2 = first_add - second_add;

    return ;
}

void solve_linear_equation(const struct coefficient coef, struct solution *sol)
{
    if (compare_double(coef.b, 0))
    {
        if (compare_double(coef.c, 0))
        {
            sol->n_roots = INF_ROOTS;
        }
        else
        {
            sol->n_roots = ZERO_ROOTS;
        }

        return ;
    }

    sol->n_roots = ONE_ROOT;
    sol->x1 = sol->x2 = (-coef.c) / coef.b;

    return ;
}

void print_solution(const struct coefficient coef, const struct solution sol)
{
    printf("Уравнение %lgx^2%+lgx%+lg=0 ", coef.a, coef.b, coef.c);

    switch (sol.n_roots)
    {
        case ZERO_ROOTS:
        {
            printf("не имеет действительных корней.\n");
            break;
        }

        case ONE_ROOT:
        {
            printf("имеет один корень:\n"
                   "x1=%lg\n",sol.x1);
            break;
        }

        case TWO_ROOTS:
        {
            printf("имеет два корня:\n"
                   "x1=%lg\n"
                   "x2=%lg\n", sol.x1, sol.x2);
            break;
        }

        case INF_ROOTS:
        {
            printf(" имеет бесконечное количество корней\n");
            break;
        }

        default:
        {
            fprintf(stderr, "ERROR: print_solutions(): %lg", sol.n_roots);
            break;
        }
    }
}

_Bool compare_double(double d1, double d2)
{
    return (fabs(d1 - d2) < EPSILON) ? 1 : 0;
}

void print_greeting()
{
    printf("Это программа для решений квадратных уравнений вида ax^2+bx+c=0.\n");
    printf("Начните вводить коэффициенты c новой строки\n");
}
