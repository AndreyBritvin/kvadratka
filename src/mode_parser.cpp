#include "mode_parser.h"

#include "test_data.h"

const char HELP_COMMAND_LONG[]  = "--help";
const char HELP_COMMAND_SHORT[] = "-h";

const char TEST_COMMAND_LONG[]  = "--test";
const char TEST_COMMAND_SHORT[] = "-t";

const char VERSION_COMMAND_LONG[]  = "--version";
const char VERSION_COMMAND_SHORT[] = "-v";

const char SOLVE_COMMAND_LONG[]  = "--solve";
const char SOLVE_COMMAND_SHORT[] = "-s";

void parse_mode(const char programm_name[], const char mode[], const int flag_num, const int argc)
{
    MY_ASSERT(programm_name != NULL);
    MY_ASSERT(mode != NULL);

    static bool is_next_filename = false;

    if (is_next_filename)
    {
        file_tests_result(mode);
        is_next_filename = false;
    }

    else if (cmp_str_to_multiple(mode, VERSION_COMMAND_SHORT, VERSION_COMMAND_LONG))
    {
        version();
    }

    else if (cmp_str_to_multiple(mode, SOLVE_COMMAND_SHORT, SOLVE_COMMAND_LONG))
    {
        solve_from_terminal();
    }

    else if (cmp_str_to_multiple(mode, TEST_COMMAND_SHORT, TEST_COMMAND_LONG))
    {
        if (flag_num == argc)
        {
            wrong_flag(programm_name, mode);
        }
        is_next_filename = true;
    }

    else if (cmp_str_to_multiple(mode, HELP_COMMAND_SHORT, HELP_COMMAND_LONG))
    {
        help();
    }

    else
    {
        wrong_flag(programm_name, mode);
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

void version()
{
    printf("Version 1.0\n");
}

bool cmp_str_to_multiple(const char *str_to_cmp, const char *str1, const char *str2)
{
    MY_ASSERT(str_to_cmp != NULL);
    MY_ASSERT(str1 != NULL);
    MY_ASSERT(str2 != NULL);


    if (!strcmp(str_to_cmp, str1) || !strcmp(str_to_cmp, str2))
    {
        return true;
    }

    return false;
}

void help()
{
    printf("%s %s\n"
           "Help command\n\n"

           "%s %s\n"
           "Print programm version\n\n"

           "%s %s [filename]\n"
           "Run unit tests from file\n\n"

           "%s %s\n"
           "Solves ax^2+bx+c=0. Enter coeefficients\n\n",
              HELP_COMMAND_SHORT,    HELP_COMMAND_LONG,
           VERSION_COMMAND_SHORT, VERSION_COMMAND_LONG,
              TEST_COMMAND_SHORT,    TEST_COMMAND_LONG,
             SOLVE_COMMAND_SHORT,   SOLVE_COMMAND_LONG);
}
