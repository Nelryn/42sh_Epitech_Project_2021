/*
** EPITECH PROJECT, 2021
** tests_echo.c
** File description:
** tests_echo
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(execute_echo, print_string, .init=redirect_all_stdout)
{
    shell_t shell = (shell_t){NULL, NULL, NULL, 0, NULL};

    char *tmp[4];
    tmp[0] = "echo";
    tmp[1] = "hello";
    tmp[2] = "tmp42hello";
    tmp[3] = NULL;
    shell.tmp = tmp;
    execute_echo(&shell);
    cr_assert_stdout_eq_str("hello tmp42hello\n");
}

Test(execute_echo, print_path, .init=redirect_all_stdout)
{
    shell_t shell = (shell_t){NULL, NULL, NULL, 0, NULL};
    char *tmp[3];
    char *env[3];

    tmp[0] = "echo";
    tmp[1] = "$path";
    tmp[2] = NULL;
    env[0] = "SHELL=/bin/bash";
    env[1] = "PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin";
    env[2] = NULL;
    shell.tmp = tmp;
    shell.env = env;
    execute_echo(&shell);
    cr_assert_stdout_eq_str("/usr/local/bin /usr/bin /bin /usr/local/sbin\n");
}

Test(execute_echo, return_value, .init=redirect_all_stdout)
{
    shell_t shell = (shell_t){NULL, NULL, NULL, 0, NULL};
    char *tmp[3];

    tmp[0] = "echo";
    tmp[1] = "$?";
    tmp[2] = NULL;
    shell.tmp = tmp;
    shell.r_value = 512;
    execute_echo(&shell);
    cr_assert_stdout_eq_str("2\n");
}