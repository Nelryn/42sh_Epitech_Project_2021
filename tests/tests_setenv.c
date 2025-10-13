/*
** EPITECH PROJECT, 2021
** test_setenv.c
** File description:
** tests_setenv
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

Test(make_setenv, many_arg, .init=redirect_all_stdout)
{
    shell_t shell = (shell_t){NULL, NULL, NULL, 0, NULL};
    char *tmp[5];
    char *env[2];

    env[0] = "SHELL=/bin/bash";
    env[1] = NULL;
    tmp[0] = "setenv";
    tmp[1] = "hello";
    tmp[2] = "world";
    tmp[3] = "toto";
    tmp[4] = NULL;
    shell.tmp = tmp;
    shell.env = env;
    shell.env = make_setenv(&shell);
    cr_assert_stderr_eq_str("setenv: Too many arguments.\n");
}

Test(make_setenv, simple_setenv, .init=redirect_all_stdout)
{
    shell_t shell = (shell_t){NULL, NULL, NULL, 0, NULL};
    char *tmp[2];
    char *env[2];

    env[0] = "SHELL=/bin/bash";
    env[1] = NULL;
    tmp[0] = "setenv";
    tmp[1] = NULL;
    shell.tmp = tmp;
    shell.env = env;
    shell.env = make_setenv(&shell);
    cr_assert_stdout_eq_str("SHELL=/bin/bash\n");
}

Test(make_setenv, number_var, .init=redirect_all_stdout)
{
    shell_t shell = (shell_t){NULL, NULL, NULL, 0, NULL};
    char *tmp[4];
    char *env[2];

    env[0] = "SHELL=/bin/bash";
    env[1] = NULL;
    tmp[0] = "setenv";
    tmp[1] = "2ello";
    tmp[2] = "world";
    tmp[3] = NULL;
    shell.tmp = tmp;
    shell.env = env;
    shell.env = make_setenv(&shell);
    cr_assert_stderr_eq_str(
        "setenv: Variable name must begin with a letter.\n");
}