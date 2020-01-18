/*
** EPITECH PROJECT, 2019
** 104intersection
** File description:
** function
*/

#ifndef FUNCTION_H_
#define FUNCTION_H_

void calc_bisection(char **av);

void calc_newton(char **av);

void calc_secant(char **av);

void display_result(long double nb, long double p);

double  check_sign_float(double nb);

int	my_diviseur(int nb);

long double		nbr_arrondi(long double nb, long double p);

int     my_other_isnum(char *str);

int     my_str_isnum(char *str);

#endif /* !FUNCTION_H_ */