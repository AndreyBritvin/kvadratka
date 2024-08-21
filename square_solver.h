#ifndef SQUARE_SOLVER_H
#define SQUARE_SOLVER_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include <math.h>

static const double EPSILON = 1e-7;

enum number_of_roots
{
    INF_ROOTS  = -1,
    ZERO_ROOTS =  0,
    ONE_ROOT   =  1,
    TWO_ROOTS  =  2,
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

void get_coefficients(struct coefficient *coef);

void solve_quadratic_equation(const struct coefficient coef, struct solution *sol);
void solve_linear_equation(const struct coefficient coef, struct solution *sol);
void solve_equation(const struct coefficient coef, struct solution *sol);

void print_solution(const struct coefficient coef, const struct solution sol);

_Bool compare_double(double d1, double d2);

void clear_buffer(_Bool print_buf);

#endif // SQUARE_SOLVER_H
