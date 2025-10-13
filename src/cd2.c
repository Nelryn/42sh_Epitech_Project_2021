/*
** EPITECH PROJECT, 2021
** cd2.c
** File description:
** cd
*/

#include "my.h"

char *find_var_env(char **env, char *var)
{
    int i = 0;
    int size = my_strlen(var);

    while (env[i] != NULL) {
        if (my_strncmp(var, env[i], size))
            return (&env[i][size]);
        i = i + 1;
    }
    return (NULL);
}

int cd_home_and_previous(shell_t *shell, char *path)
{
    char *home = NULL;

    if (my_arrlen(shell->tmp) == 1 || str_compare(shell->tmp[1], "~")) {
        if ((home = find_var_env(shell->env, "HOME=")) != NULL)
            chdir(home);
        set_old_pwd(path, shell);
        return (0);
    }
    if (str_compare(shell->tmp[1], "-")) {
        if (get_old_pwd(shell->env) == NULL) {
            write(2, ": No such file or directory.\n", 29);
            shell->r_value = 511;
            return (0);
        }
        chdir(get_old_pwd(shell->env));
        return (0);
    }
    return (1);
}
