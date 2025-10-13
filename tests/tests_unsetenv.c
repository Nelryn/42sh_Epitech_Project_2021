/*
** EPITECH PROJECT, 2021
** tests_unsetenv.c
** File description:
** tests_unsetenv
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

Test(make_unsetenv, delete_var)
{
    shell_t shell = (shell_t){NULL, NULL, NULL, 0, NULL};
    char *tmp[3];
    char *env[3];
    char *new[2];

    env[0] = "SHELL=/bin/bash";
    env[1] = "PATH=/org";
    env[2] = NULL;
    tmp[0] = "unsetenv";
    tmp[1] = "PATH";
    tmp[2] = NULL;
    new[0] = "SHELL=/bin/bash";
    new[1] = NULL;
    shell.tmp = tmp;
    shell.env = env;
    shell.env = make_unsetenv(&shell);
    cr_assert_arr_eq(shell.env, new, 0);
}