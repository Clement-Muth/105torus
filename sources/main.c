/*
** EPITECH PROJECT, 2020
** 105torus_2019
** File description:
** main
*/

#include <main/main.h>

static void pres()
{
    printf("USAGE\n");
    printf("    ./105torus opt a0 a1 a2 a3 a4 n\n");
    printf("\nDESCRIPTION\n");
    printf("    opt       method option:\n");
    printf("\t\t  1 for the bisection method\n");
    printf("\t\t  2 for Newton’s method\n");
    printf("\t\t  3 for the secant method\n");
    printf("    a[0-4]    coefficients of the equation\n");
    printf("    n         precision (the application of the polynomial to the solution should\n");
    printf("\t      be smaller than 10ˆ-n)\n");
}

static _Bool error_handling(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == true) {
        pres();
        exit(0);
    }
    if (ac != 8)
        return (false);
    if ((my_strcmp(av[1], "1") == false) && (my_strcmp(av[1], "2") == false) &&
    (my_strcmp(av[1], "3") == false) && my_atoi(av[7]) < 0)
        return (false);
    for (int i = 1; i < ac - 1; ++i)
        if (!is_strnum(av[i]))
            return (false);
    return (true);
}

void (*opt_fct[])(char **) = {
    calc_bisection,
    calc_newton,
    calc_secant
};

int main(int ac, char **av)
{
    int opt[] = {1, 2, 3, '\0'};

    if (!error_handling(ac, av))
        return (EXIT_ERROR);
    for (int i = 0; opt[i]; ++i)
        if (opt[i] == my_atoi(av[1]))
            opt_fct[i](av);
    return (EXIT_SUCCESS);
}
