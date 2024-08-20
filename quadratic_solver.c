#include <stdio.h>
#include <math.h>

const double EPSILON = 1e-7;

enum number_of_roots
{
    INF_ROOTS = -1,
    ZERO_ROOTS,
    ONE_ROOT,
    TWO_ROOTS
};

struct solution
{
    int n_roots;
    double x1;
    double x2;
};

struct coefficient
{
    double a;
    double b;
    double c;
};

void print_greeting();
double get_one_coef(char parametr);
void get_coefficients(struct coefficient *coef);
void solve_quadratic_equation(const struct coefficient coef, struct solution *sol);
void solve_linear_equation(const struct coefficient coef, struct solution *sol);
void solve_equation(const struct coefficient coef, struct solution *sol);
void print_solution(const struct coefficient coef, const struct solution sol);
int compare_double(double d1, double d2);


int main()
{
    print_greeting();

    char is_quit;
    do{
        struct coefficient coeffs = {0, 0, 0};
        struct solution sol = {0, 0, 0};

        get_coefficients(&coeffs);
        solve_equation(coeffs, &sol);
        print_solution(coeffs, sol);

        printf("Решить новое уравнение? Введите y для продолжения, n для выхода из программы\n");

        getchar();//skip \n from previous coef
        if ((is_quit=getchar()) == 'n')
        {
            break;
        }
        while ((is_quit=getchar()) != '\n')
            continue;
    }
    while(is_quit != EOF);

    return 0;
}

double get_one_coef(char parametr)
{
    double coef;
    char ch;

    printf("Пожалуйста, введите коэффициент %c\n",parametr);
    while (scanf("%lf", &coef) != 1) // ещё надо придумать, как отфильтровать значение а~0
    {
        while((ch = getchar()) != '\n')
        {
            putchar(ch);
        }
        printf(" не является допустимым вводом. Введите целое или дробное число, например: 1.618 или 3.14\n");
    }
    return coef;
}

void get_coefficients(struct coefficient *coef)
{
    coef->a = get_one_coef('a');
    coef->b = get_one_coef('b');
    coef->c = get_one_coef('c');
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
    double discriminant = coef.b*coef.b-4*coef.a*coef.c;

    if (discriminant<0)
    {
        sol->n_roots = ZERO_ROOTS;
        sol->x1 = sol->x2 = 0;

        return ;
    }

    if (compare_double(discriminant, 0))
    {
        sol->n_roots = ONE_ROOT;
        sol->x1 = sol->x2 = (-coef.b)/(2*coef.a);

        return ;
    }

    sol->n_roots = TWO_ROOTS;
    sol->x1 = (-coef.b + sqrt(discriminant)) / (2*coef.a);
    sol->x2 = (-coef.b - sqrt(discriminant)) / (2*coef.a);

    return ;
}

void solve_linear_equation(const struct coefficient coef, struct solution *sol)
{
    if (compare_double(coef.b, 0))
    {
        sol->n_roots = INF_ROOTS;
        sol->x1 = sol->x2 = 0;
        return ;
    }

    sol->n_roots = ONE_ROOT;
    sol->x1 = sol->x2 = (-coef.c) /coef.b;

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
            printf(" имеет бесконечное количество корней");
            break;
        }

        default:
        {
            fprintf(stderr, "ERROR: print_solutions(): %lg", sol.n_roots);
            break;
        }
    }
}

int compare_double(double d1, double d2)
{
    return (fabs(d1-d2)<EPSILON) ? 1: 0;
}

void print_greeting()
{
    printf("Это программа для решений квадратных уравнений вида ax^2+bx+c=0.\n");
    printf("Начните вводить коэффициенты c новой строки\n");
}
