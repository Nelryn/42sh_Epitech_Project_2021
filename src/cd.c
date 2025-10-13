/*
** EPITECH PROJECT, 2021
** B-PSU-101-RUN-1-1-minishell1-hugo.baret
** File description:
** cd
*/

#include "my.h"

void set_old_pwd(char *path, shell_t *shell)
{
    shell->tmp = malloc(sizeof(char *) * (4));
    shell->tmp[0] = my_strdup("setenv");
    shell->tmp[1] = my_strdup("OLDPWD");
    shell->tmp[2] = my_strdup(path);
    shell->tmp[3] = NULL;
    make_setenv(shell);
}

void set_new_pwd(char *path, shell_t *shell)
{
    shell->tmp = malloc(sizeof(char *) * (4));
    shell->tmp[0] = my_strdup("setenv");
    shell->tmp[1] = my_strdup("PWD");
    shell->tmp[2] = my_strdup(path);
    shell->tmp[3] = NULL;
    make_setenv(shell);
}

char *get_old_pwd(char **env)
{
    char **tmp = NULL;

    for (int i = 0; env[i]; i++) {
        if (my_strncmp("OLDPWD", env[i], 6)) {
            tmp = my_str_to_word_array(env[i], '=');
            return (tmp[1]);
        }
    }
    return NULL;
}

void make_cd(shell_t *shell)
{
    char *path = NULL;
    char *tmp = NULL;

    if (my_arrlen(shell->tmp) > 2) {
        write (2, "cd: Too many arguments.\n", 24);
        shell->r_value = 511;
        return;
    }
    path = getcwd(NULL, 0);
    if (cd_home_and_previous(shell, path) == 1) {
        tmp = my_strdup(shell->tmp[1]);
        set_old_pwd(path, shell);
        if (chdir(tmp) == -1)
            cd_error(tmp, shell);
    }
    path = getcwd(NULL, 0);
    set_new_pwd(path, shell);
}
