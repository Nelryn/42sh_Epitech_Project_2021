/*
** EPITECH PROJECT, 2021
** B-PSU-210-RUN-2-1-42sh-emilie.baunifais
** File description:
** where
*/

#include "my.h"

bool check_char(char *s, char sep)
{
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == sep)
            return true;
    }
    return false;
}

int print_path(char **old_path, char **buf, int index)
{
    int check = 0;
    char *path = NULL;
    struct stat s;
    int i = 0;

    while (old_path[i]) {
        path = my_strcat(old_path[i], buf[index]);
        if (stat(path, &s) != -1) {
            my_printf("%s\n", path);
            check = 1;
        }
        i++;
    }
    return check;
}

int check_alias(char *name_cmd, alias_t *alias)
{
    for (; alias != NULL; alias = alias->next) {
        if (str_compare(name_cmd, alias->alias_name) == 1) {
            my_printf("%s is aliased to %s\n", name_cmd, alias->alias_do);
            return 1;
        }
    }
    return 0;
}

void some_where(shell_t *shell, int save)
{
    int check = 0;
    char **path2 = NULL;

    if (my_arrlen(shell->tmp) == 1) {
        my_puterror("where: Too few arguments.\n");
        shell->r_value = 511;
        return;
    }
    for (int i = 1; shell->tmp[i] != NULL; check = 0, free_array(path2), i++) {
        check += check_alias(shell->tmp[i], shell->aliases);
        path2 = find_the_path(shell->env, path2);
        if (check_char(shell->tmp[i], '/')) {
            my_puterror("where: / in command makes no sense\n");
            shell->r_value = 511;
        }
        if (check_builtin(shell->tmp[i]) == 1)
            my_printf("%s is a shell built-in\n", shell->tmp[i]);
        check += print_path(path2, shell->tmp, i);
        save += (check == 0) ? 1 : 0;
    }
    (save != 0) ? shell->r_value = 511 : 0;
}