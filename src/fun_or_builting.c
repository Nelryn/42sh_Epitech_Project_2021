/*
** EPITECH PROJECT, 2021
** B-PSU-101-RUN-1-1-minishell1-hugo.baret
** File description:
** fun_or_builting
*/

#include "my.h"
#include "pipe.h"

int check_builtin(char *cmd)
{
    int check = 0;

    check += (str_compare(cmd, "setenv")) ? 1 : 0;
    check += (str_compare(cmd, "unsetenv")) ? 1 : 0;
    check += (str_compare(cmd, "cd")) ? 1 : 0;
    check += (str_compare(cmd, "where")) ? 1 : 0;
    check += (str_compare(cmd, "which")) ? 1 : 0;
    check += (str_compare(cmd, "exit")) ? 1 : 0;
    return check;
}

void fun_or_builtin3(shell_t *shell, int pipe)
{
    if (str_compare(shell->tmp[0], "alias")) {
        alias(shell);
        return;
    }
    if (str_compare(shell->tmp[0], "unalias")) {
        unalias(shell);
        return;
    }
    (!str_compare(shell->tmp[0], "")) ? function(shell, pipe) : 0;
}

void fun_or_builtin2(shell_t *shell, int pipe)
{
    if (str_compare(shell->tmp[0], "unsetenv")) {
        shell->env = make_unsetenv(shell);
        return;
    }
    if (str_compare(shell->tmp[0], "cd")) {
        make_cd(shell);
        return;
    }
    if (str_compare(shell->tmp[0], "where")) {
        some_where(shell, 0);
        return;
    }
    if (str_compare(shell->tmp[0], "which")) {
        which_one(shell);
        return;
    }
    fun_or_builtin3(shell, pipe);
}

void fun_or_builtin(shell_t *shell, int pipe)
{
    char **tab = is_it_an_alias(shell->aliases, shell->tmp[0]);

    if (tab == NULL)
        return;
    shell->tmp = mix_tabs(shell->tmp, tab);
    (str_compare(shell->tmp[0], "exit")) ? get_out(shell->buf) : 0;
    if (str_compare(shell->tmp[0], "env")) {
        print_arr(shell->env);
        return;
    }
    if (str_compare(shell->tmp[0], "echo")) {
        execute_echo(shell);
        return;
    }
    if (str_compare(shell->tmp[0], "setenv")) {
        shell->env = make_setenv(shell);
        return;
    } else
        fun_or_builtin2(shell, pipe);
}