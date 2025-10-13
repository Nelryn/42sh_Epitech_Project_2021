/*
** EPITECH PROJECT, 2021
** B-PSU-101-RUN-1-1-minishell1-hugo.baret
** File description:
** env
*/

#include "my.h"

char **make_tmp(char **env_dup, char **env)
{
    int line = 0;
    int i = 0;

    line = my_arrlen(env);
    env_dup = malloc(sizeof(char *) * (line + 2));
    for (i = 0; env[i]; i++)
        env_dup[i] = my_strdup(env[i]);
    return (env_dup);
}

int check_env_arg(shell_t *shell)
{
    int i = 1;

    if (my_arrlen(shell->tmp) > 3) {
        write(2, "setenv: Too many arguments.\n", 28);
        i = 0;
    } else if (my_arrlen(shell->tmp) == 1) {
        print_arr(shell->env);
        return 0;
    }
    if (!my_isalpha(shell->tmp[1][0]) && i == 1) {
        write(2, "setenv: Variable name must begin with a letter.\n", 48);
        i = 0;
    }
    if (!my_str_isalphanum(shell->tmp[1]) && i == 1) {
        write(2,
        "setenv: Variable name must contain alphanumeric characters.\n", 61);
        i = 0;
    }
    return (i);
}

char **cond1(char **env, char **buf, int i, int count)
{
    env[i] = my_strdup(my_strcat(my_strcat(buf[1], "="), buf[2]));
    if (i != count)
        env[i + 1] = NULL;
    return env;
}

char **cond2(char **env, char **buf, int i, int count)
{
    env[i] = my_strdup(my_strcat(buf[1], "="));
    if (i != count)
        env[i + 1] = NULL;
    return env;
}

char **make_setenv(shell_t *shell)
{
    char **tmp = NULL;
    char **tmp_env = NULL;
    int count = 0;
    int i = 0;

    if (!check_env_arg(shell)) {
        shell->r_value = 511;
        return shell->env;
    }
    tmp_env = make_tmp(tmp_env, shell->env);
    for (i = 0; shell->env[i]; i++) {
        tmp = my_str_to_word_array(shell->env[i], '=');
        if (str_compare(tmp[0], shell->tmp[1])) {
            count = i;
            break;
        }
    }
    free_array(tmp);
    tmp_env = make_setenv2(shell, i, count, tmp_env);
    return (tmp_env);
}
