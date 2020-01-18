/*
** EPITECH PROJECT, 2019
** 104intersection
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct
{
    size_t size;
    int ac;
    char *command;
    char *path;
    char **av;
    char **evrnmt;
} main_t;

#endif /* !STRUCT_H_int */