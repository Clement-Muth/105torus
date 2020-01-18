/*
** EPITECH PROJECT, 2020
** 105torus_2019
** File description:
** process
*/

#include <main/main.h>

void calc_bisection(char **av)
{
    long double x1 = 0, x2 = 1, Xn = (x1 + x2) / 2;
    long double Fx1 = (atof(av[6]) * pow(x1, 4)) + (atof(av[5]) * pow(x1, 3)) + (atof(av[4]) * pow(x1, 2)) + (atof(av[3]) * x1) + atof(av[2]);
    long double Fx2 = (atof(av[6]) * pow(x2, 4)) + (atof(av[5]) * pow(x2, 3)) + (atof(av[4]) * pow(x2, 2)) + (atof(av[3]) * x2) + atof(av[2]);
    long double FXn = (atof(av[6]) * pow(Xn, 4)) + (atof(av[5]) * pow(Xn, 3)) + (atof(av[4]) * pow(Xn, 2)) + (atof(av[3]) * Xn) + atof(av[2]);
    long double n = pow(10, -(atof(av[7])));
    int i = -1;

    if (fabs(FXn) < n)
        display_result(Xn, atof(av[7]));
    while (fabs(FXn) > n && ++i < 50) {
        Xn = (x1 + x2) / 2;
        Fx1 = (atof(av[6]) * pow(x1, 4)) + (atof(av[5]) * pow(x1, 3)) + (atof(av[4]) * pow(x1, 2)) + (atof(av[3]) * x1) + atof(av[2]);
        Fx2 = (atof(av[6]) * pow(x2, 4)) + (atof(av[5]) * pow(x2, 3)) + (atof(av[4]) * pow(x2, 2)) + (atof(av[3]) * x2) + atof(av[2]);
        FXn = (atof(av[6]) * pow(Xn, 4)) + (atof(av[5]) * pow(Xn, 3)) + (atof(av[4]) * pow(Xn, 2)) + (atof(av[3]) * Xn) + atof(av[2]);
        if ((Fx1 * FXn) < 0)
            x2 = Xn;
        else
            x1 = Xn;
        display_result(Xn, atof(av[7]));
    }
}

void calc_newton(char **av)
{
    long double Xn = 0.5, n = pow(10, -(atoi(av[7])));
    long double FXn = (atof(av[6]) * pow(Xn, 4)) + (atof(av[5]) * pow(Xn, 3)) + (atof(av[4]) * pow(Xn, 2)) + (atof(av[3]) * Xn) + atof(av[2]);
    long double FdXn = FdXn = (4 * atof(av[6]) * pow(Xn, 3)) + (3 * atof(av[5]) * pow(Xn, 2)) + (2 * atof(av[4]) * Xn) + (atof(av[3]) * Xn);
    long double XN = Xn - (FXn / FdXn);
    long double FXN = FXN = (atof(av[6]) * pow(XN, 4)) + (atof(av[5]) * pow(XN, 3)) + (atof(av[4]) * pow(XN, 2)) + (atof(av[3]) * XN) + atof(av[2]);
    int i = -1;

    if (fabs(FXn) < n)
        display_result(Xn, atof(av[7]));
    while (fabs(FXN) > n && ++i <= 250) {
        FXn = (atof(av[6]) * pow(Xn, 4)) + (atof(av[5]) * pow(Xn, 3)) + (atof(av[4]) * pow(Xn, 2)) + (atof(av[3]) * Xn) + atof(av[2]);
        FdXn = (4 * atof(av[6]) * pow(Xn, 3)) + (3 * atof(av[5]) * pow(Xn, 2)) + (2 * atof(av[4]) * Xn) + (atof(av[3]) * Xn);
        FXN = (atof(av[6]) * pow(XN, 4)) + (atof(av[5]) * pow(XN, 3)) + (atof(av[4]) * pow(XN, 2)) + (atof(av[3]) * XN) + atof(av[2]);
        if (FdXn == 0)
            exit (EXIT_ERROR);
        display_result(Xn, atof(av[7]));
        XN = Xn - (FXn / FdXn);
        Xn = XN;
    }
}

static int check_convergence(char **av, long double x1, long double x2, long double Fx1, long double Fx2, long double Xn, long double FXn, long double n)
{
    int i = -1;

    while (fabs(FXn) > n && ++i <= 250) {
        Fx1 = atof(av[6]) * pow(x1, 4) + atof(av[5]) * pow(x1, 3) + atof(av[4]) * pow(x1, 2) + atof(av[3]) * x1 + atof(av[2]);
        Fx2 = atof(av[6]) * pow(x2, 4) + atof(av[5]) * pow(x2, 3) + atof(av[4]) * pow(x2, 2) + atof(av[3]) * x2 + atof(av[2]);
        if (Fx2 - Fx1 == 0)
            exit (EXIT_ERROR);
        Xn = x2 - (Fx2 * (x2 - x1) / (Fx2 - Fx1));
        FXn = atof(av[6]) * pow(Xn, 4) + atof(av[5]) * pow(Xn, 3) + atof(av[4]) * pow(Xn, 2) + atof(av[3]) * Xn + atof(av[2]);
        x1 = x2;
        x2 = Xn;
    }
    return (i);
}

void calc_secant(char **av)
{
    long double x1 = 0, x2 = 1, n = pow(10, -atof(av[7]));
    long double Fx1 = atof(av[6]) * pow(x1, 4) + atof(av[5]) * pow(x1, 3) + atof(av[4]) * pow(x1, 2) + atof(av[3]) * x1 + atof(av[2]);
    long double Fx2 = atof(av[6]) * pow(x2, 4) + atof(av[5]) * pow(x2, 3) + atof(av[4]) * pow(x2, 2) + atof(av[3]) * x2 + atof(av[2]);
    long double Xn = x2 - (Fx2 * (x2 - x1) / (Fx2 - Fx1));
    long double FXn = atof(av[6]) * pow(Xn, 4) + atof(av[5]) * pow(Xn, 3) + atof(av[4]) * pow(Xn, 2) + atof(av[3]) * Xn + atof(av[2]);
    int i = check_convergence(av, x1, x2, Fx1, Fx2, Xn, FXn, n);

    if (fabs(FXn) < n)
        display_result(Xn, atof(av[7]));
    else if (i >= 250)
        exit(EXIT_ERROR);
    while (fabs(FXn) > n) {
        Fx1 = atof(av[6]) * pow(x1, 4) + atof(av[5]) * pow(x1, 3) + atof(av[4]) * pow(x1, 2) + atof(av[3]) * x1 + atof(av[2]);
        Fx2 = atof(av[6]) * pow(x2, 4) + atof(av[5]) * pow(x2, 3) + atof(av[4]) * pow(x2, 2) + atof(av[3]) * x2 + atof(av[2]);
        if (Fx2 - Fx1 == 0)
            exit (EXIT_ERROR);
        Xn = x2 - (Fx2 * (x2 - x1) / (Fx2 - Fx1));
        FXn = atof(av[6]) * pow(Xn, 4) + atof(av[5]) * pow(Xn, 3) + atof(av[4]) * pow(Xn, 2) + atof(av[3]) * Xn + atof(av[2]);
        x1 = x2;
        x2 = Xn;
        display_result(Xn, atof(av[7]));
    }
}