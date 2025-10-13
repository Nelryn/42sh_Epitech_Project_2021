/*
** EPITECH PROJECT, 2021
** B-PSU-101-RUN-1-1-minishell1-hugo.baret
** File description:
** mysh
*/

#include "my.h"

int main(int ac, char **av UNUSED, char **env)
{
    shell_t shell = {NULL, NULL, NULL, 0, NULL};

    if (ac != 1)
        return 84;
    shell.env = make_env(shell.env, env);
    mysh(&shell);
    free_all(&shell);
    return 0;
}