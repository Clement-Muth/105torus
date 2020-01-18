/*
** EPITECH PROJECT, 2020
** 105torus_2019
** File description:
** display
*/

#include <main/main.h>

void display_result(long double nb, long double p)
{
    int i = -1;

    printf("x = ");
    nb *= pow(10, p);
    nb = ((nb - floor(nb)) > 0.5) ? nb + 0.5 : nb;
    nb /= pow(10, p);
    printf("%.0f", floor(nb));
    nb -= floor(nb);
    printf(".");
    while (++i < p && nb != 0) {
        nb *= 10.0;
        printf("%.0f", floor(nb));
        nb -= floor(nb);
    }
    printf("\n");
}
