/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** is_alphanum
*/

#include "include/my.h"

_Bool is_alphanum(char c)
{
    return (c < '0' || c > '9') ? (false) : (true);
}