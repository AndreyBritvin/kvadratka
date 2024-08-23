#include "square_solver.h"

void get_coefficients(struct coefficient *coef)
{
    printf("Пожалуйста, введите коэффициенты a, b, c\n");

    int ret = 0;

    while ( (ret = scanf("%lf %lf %lf", &coef->a, &coef->b, &coef->c)) != 3)
    {
        clear_buffer(true);

        printf(" не является допустимым вводом. Введите целое или дробное число, например: 1.618 или 3.14\n");
    }

    clear_buffer(false);

    return ;
}


void solve_equation(const struct coefficient coef, struct solution *sol)
{
    if (compare_equal_double(coef.a, 0))
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
    MY_ASSERT(sol != NULL);

    MY_ASSERT(isfinite(coef.a));
    MY_ASSERT(isfinite(coef.b));
    MY_ASSERT(isfinite(coef.c));

    MY_ASSERT(!isnan(coef.a));
    MY_ASSERT(!isnan(coef.b));
    MY_ASSERT(!isnan(coef.c));

    double discriminant = coef.b * coef.b - 4 * coef.a * coef.c;

    MY_ASSERT(isfinite(discriminant));
    MY_ASSERT(!isnan(discriminant));

    double first_add = (-coef.b) / (2 * coef.a);

    if (compare_equal_double(discriminant, 0))
    {
        sol->n_roots = ONE_ROOT;
        sol->x1 = sol->x2 = first_add;

        return ;
    }

    if (discriminant < 0)
    {
        sol->n_roots = ZERO_ROOTS;

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
    if (compare_equal_double(coef.b, 0))
    {
        if (compare_equal_double(coef.c, 0))
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
                   "x1 = %lg\n",sol.x1);
            break;
        }

        case TWO_ROOTS:
        {
            printf("имеет два корня:\n"
                   "x1 = %lg\n"
                   "x2 = %lg\n", sol.x1, sol.x2);
            break;
        }

        case INF_ROOTS:
        {
            printf(" имеет бесконечное количество корней\n");
            break;
        }

        default:
        {
            fprintf(stderr, "ERROR: print_solutions(): %d", sol.n_roots);
            break;
        }
    }
}

void print_greeting()
{
    printf("Это программа для решений квадратных уравнений вида ax^2+bx+c=0.\n");
    printf("Начните вводить коэффициенты c новой строки\n");
}

void clear_buffer(_Bool print_buf)
{
    int ch = 0;
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        if(print_buf)
        {
            printf("%c", ch);
        }
        else
        {
            continue;
        }
    }
}
