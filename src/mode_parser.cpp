#include "mode_parser.h"

#include "test_data.h"

enum mode_index
{
    MODE_1,
    MODE_2,
};


void parse_mode(const char programm_name[], const char mode[], const int flag_num, const int argc)
{
    MY_ASSERT(programm_name != NULL);
    MY_ASSERT(mode != NULL);

    static bool is_next_filename = false;

    if (is_next_filename)
    {
        tests_result(mode);
        is_next_filename = false;
    }

    else if (cmp_str_to_multiple(mode, "-v", "--version"))
    {
        version();
    }

    else if (cmp_str_to_multiple(mode, "-s", "--solve"))
    {
        solve_from_terminal();
    }

    else if (cmp_str_to_multiple(mode, "-t", "--test"))
    {
        if (flag_num == argc)
        {
            wrong_flag(programm_name, mode);
        }
        is_next_filename = true;
    }

    else if (cmp_str_to_multiple(mode, "-h", "--help"))
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


void tests_result(const char filename[])
{
    FILE *fp; // File to unit test data

    struct unit_test_input to_test[MAX_UNIT_TEST_COUNT] = {};

    if(int error_num = open_file(&fp, filename))
    {
        printf("Error: %s\n", strerror(error_num));

        exit(EXIT_FAILURE);
    }

    unsigned int TEST_COUNT = file_unit_test_output(&fp, to_test);

    if(int error_num = close_file(&fp, filename))
    {
        printf("Error: %s\n", strerror(error_num));

        exit(EXIT_FAILURE);
    }

    printf("Неверно пройденных тестов: %d/%u\n", run_all_tests(all_tests, TEST_COUNT), TEST_COUNT);
}

void help()
{
    printf("-h --help\n"
           "Help command\n\n"

            "-v --version\n"
           "Print programm version\n\n"

           "-t --test [filename]\n"
           "Run unit tests from file\n\n"

           "-s --solve\n"
           "Solves ax^2+bx+c=0. Enter coeefficients\n\n");
}
