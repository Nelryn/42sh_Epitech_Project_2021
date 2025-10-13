/*
** EPITECH PROJECT, 2021
** tests_mysh.c
** File description:
** tests_mysh
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

Test(make_env, copy_env)
{
    char *env[4];
    char **env_copy = NULL;

    env[0] = "SHELL=/bin/bash";
    env[0] = "PWD=/B-PSU-210-RUN-2-1-42sh-emilie.baunifais";
    env[0] = "HOME=/home";
    env[0] = NULL;
    env_copy = make_env(env_copy, env);
    cr_assert_arr_eq(env_copy, env, 0);
    free_array(env_copy);
}

Test(handle_status, floating_exception, .init=redirect_all_stdout)
{
    handle_status(136);
    cr_assert_stderr_eq_str("Floating exception (core dumped)\n");
}

Test(handle_status, abort, .init=redirect_all_stdout)
{
    handle_status(134);
    cr_assert_stderr_eq_str("Abort (core dumped)\n");
}

Test(handle_status, segmentation_fault, .init=redirect_all_stdout)
{
    handle_status(139);
    cr_assert_stderr_eq_str("Segmentation fault (core dumped)\n");
}

Test(handle_status, bus_error, .init=redirect_all_stdout)
{
    handle_status(135);
    cr_assert_stderr_eq_str("Bus error (core dumped)\n");
}