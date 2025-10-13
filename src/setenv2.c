/*
** EPITECH PROJECT, 2021
** setenv2.c
** File description:
** setenv2
*/

#include "my.h"

char **make_setenv2(shell_t *shell, int i, int count, char **tmp_env)
{
    if (my_arrlen(shell->tmp) == 3)
        tmp_env = cond1(tmp_env, shell->tmp, i, count);
    else
        tmp_env = cond2(tmp_env, shell->tmp, i, count);
    return (tmp_env);
}