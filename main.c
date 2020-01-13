/*
** EPITECH PROJECT, 2020
** 105torus_2019
** File description:
** main
*/

int usage(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        write (1, "USAGE\n", 6);
        write (1, "    ./105torus opt a0 a1 a2 a3 a4 n\n", 35);
        write (1, "\nDESCRIPTION\n", 15);
        write (1, "    opt      method option:", 20);
        write (1, "                  1 for the bisection method\n", 42);
        write (1, "                  2 for Newton's method\n", 37);
        write (1, "                  3 for the secant method\n", 39);
        write (1, "    a[0-4]   coefficients of the equation\n", 39);
        write (1, "    n        precision (the application of the polynomial to the solution sould be smaller than 10^⁻n", 76);
        return (0);
    }
    return (0);
}

int main(int ac, char **av)
{
    if (ac == 2 && av[1] == "-h") {
        usage(ac, av);
    }
    return (0);
}