/*
** EPITECH PROJECT, 2020
** 105torus
** File description:
** is_strnum
*/

#include "include/my.h"

_Bool is_strnum(char *str)
{
    int count = 0;

    for (; *str; *str++) {
        if (!is_alphanum(*str) && *str != '-' && *str != '.' && *str != '+')
            return (false);
        else if (*str == '.')
            ++count;
    }
    return (count > 1) ? (false) : (true);
}