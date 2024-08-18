#include <stdio.h>
#include <math.h>

#define EPSILON 1e-5

void solve_quadratic_equation(double coef_a,double coef_b,double coef_c);
double get_coef(char parametr);

int main()
{
    printf("Это программа для решений квадратных уравнений вида ax^2+bx+c=0.\n");
    printf("Начните вводить коэффициенты c новой строки\n");

    char is_quit;
    do{
        solve_quadratic_equation(get_coef('a'),get_coef('b'),get_coef('c'));
        printf("Решить новое уравнение? Введите y для продолжения, n для выхода из программы\n");

        getchar();//skip \n from previous coef
        if ((is_quit=getchar())=='n')
        {
            break;
        }
        while ((is_quit=getchar())!='\n')
            continue;
    }
    while(is_quit!=EOF);
    return 0;
}

double get_coef(char parametr)
{
    double coef;
    char ch;

    printf("Пожалуйста, введите коэффициент %c\n",parametr);
    while (scanf("%lf", &coef)!=1) // ещё надо придумать, как отфильтровать значение а~0
    {
        while((ch = getchar())!='\n')
        {
            putchar(ch);
        }
        printf(" не является допустимым вводом. Введите целое или дробное число, например: 1.618 или 3.14\n");
    }
    return coef;
}

void solve_quadratic_equation(double coef_a,double coef_b,double coef_c)
{
    double discriminant = coef_b*coef_b-4*coef_a*coef_c;

    printf("Уравнение %lgx^2%+lgx%+lg=0 ",coef_a,coef_b,coef_c);
    if (discriminant<0)
    {
        printf("не имеет действительных решений.\n");    
        return;
    }
    if (fabs(discriminant-0)<EPSILON)
    {
        double x1 = (-coef_b)/(2*coef_a);
        printf("имеет одно решение: x=%lg\n",x1);
        return;
    }

    double x1 = (-coef_b+sqrt(discriminant))/(2*coef_a);
    double x2 = (-coef_b-sqrt(discriminant))/(2*coef_a);
    printf("имеет два решения: x1=%lg и x2=%lg\n",x1,x2);
}


