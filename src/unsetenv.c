/*
** EPITECH PROJECT, 2021
** B-PSU-101-RUN-1-1-minishell1-hugo.baret
** File description:
** unsetenv
*/

#include "my.h"

char **make_tmp2(char **env_dup, char **env)
{
    int line = 0;

    line = my_arrlen(env);
    env_dup = malloc(sizeof(char *) * (line + 1));
    return (env_dup);
}

int check_unset_arg(shell_t *shell)
{
    if (my_arrlen(shell->tmp) < 2) {
        write(2, "unsetenv: Too few arguments.\n", 29);
        if (isatty(0) == 0)
            exit(84);
        return 0;
    }
    return 1;
}

char **make_unsetenv2(shell_t *shell, char **tmp_env, int j)
{
    int a = 0;
    char **tmp = NULL;

    tmp_env = make_tmp2(tmp_env, shell->env);
    for (int i = 0; shell->env[i]; i++) {
        tmp = my_str_to_word_array(shell->env[i], '=');
        if (!str_compare(tmp[0], shell->tmp[j])) {
            tmp_env[a] = my_strdup(shell->env[i]);
            a++;
        }
        free_array(tmp);
    }
    tmp_env[a] = NULL;
    return (tmp_env);
}

char **make_unsetenv(shell_t *shell)
{
    char **tmp_env = NULL;

    if (!check_unset_arg(shell)) {
        shell->r_value = 511;
        return shell->env;
    }
    for (int j = 1; shell->tmp[j]; j++) {
        tmp_env = make_unsetenv2(shell, tmp_env, j);
        shell->env = tmp_env;
    }
    return (shell->env);
}