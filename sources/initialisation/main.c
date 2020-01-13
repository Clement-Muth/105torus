/*
** EPITECH PROJECT, 2020
** 105torus_2019
** File description:
** main
*/

#include "main/main.h"

static void usage(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        my_printf("USAGE\n");
        my_printf("    ./105torus opt a0 a1 a2 a3 a4 n\n\n");
        my_printf("DESCRIPTION\n");
        my_printf("    opt      method option:\n");
        my_printf("\t\t 1 for the bisection method\n");
        my_printf("\t\t 2 for Newton’s method\n");
        my_printf("\t\t 3 for the secant method\n");
        my_printf("    a[0-4]   coefficients of the equation\n");
        my_printf("    n        precision (the application of the polynomial" \
        "to the solution should\n\t     be smaller than 10^-n)\n");
    }
}

int main(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        usage(ac, av);
    return (0);
}