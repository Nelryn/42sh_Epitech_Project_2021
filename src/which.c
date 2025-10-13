/*
** EPITECH PROJECT, 2021
** B-PSU-210-RUN-2-1-42sh-emilie.baunifais
** File description:
** which
*/

#include "my.h"

int check_cmd(char **to_cat_path, char **buf, int index)
{
    char *path = NULL;
    struct stat s;
    int i = 0;

    while (to_cat_path[i]) {
        path = my_strcat(to_cat_path[i], buf[index]);
        if (stat(path, &s) != -1) {
            my_printf("%s\n", path);
            return 1;
        }
        i++;
    }
    my_puterror(buf[index]);
    my_puterror(": Command not found.\n");
    return 0;
}

int check_which_alias(char *name_cmd, alias_t *alias)
{
    for (; alias != NULL; alias = alias->next) {
        if (str_compare(name_cmd, alias->alias_name) == 1) {
            my_printf("%s:\taliased to %s\n", name_cmd, alias->alias_do);
            return 1;
        }
    }
    return 0;
}

void which_one(shell_t *shell)
{
    int check = 0;
    char **path2 = NULL;

    if (my_arrlen(shell->tmp) == 1) {
        my_puterror("which: Too few arguments.\n");
        shell->r_value = 511;
        return;
    }
    for (int i = 1; shell->tmp[i] != NULL; check = 0, i++) {
        check += check_which_alias(shell->tmp[i], shell->aliases);
        path2 = find_the_path(shell->env, path2);
        if (check == 0 && (check += check_builtin(shell->tmp[i])) == 1)
            my_printf("%s is a shell built-in\n", shell->tmp[i]);
        if (check == 0 && check_cmd(path2, shell->tmp, i) != 1)
            shell->r_value = 511;
        free_array(path2);
    }
}