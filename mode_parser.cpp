#include "mode_parser.h"


enum mode_index
{
    MODE_1,
    MODE_2,
};

void parse_mode(const char programm_name[], const char mode[])
{
    if      (!strcmp(mode, "-v") || !strcmp(mode, "--version"))
    {
        print_version();
    }
}

void wrong_flag(const char programm_name[], const char wrong_mode[])
{
    printf("!--------------------------------\n"
           "! Неверный флаг %s\n"
           "! Введите %s -h для помощи\n"
           "!--------------------------------\n",
            wrong_mode, programm_name);
}

void solve_from_terminal()
{
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
}

void print_version()
{
    printf("I dont know which version it is\n");
}
