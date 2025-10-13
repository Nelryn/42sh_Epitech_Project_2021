/*
** EPITECH PROJECT, 2021
** B-PSU-210-RUN-2-1-42sh-emilie.baunifais
** File description:
** alias_02
*/

#include "my.h"
#include "pipe.h"

char *get_alias_do(char **args)
{
    char *res = NULL;

    for (int i = 2; args[i]; i++) {
        res = my_strcat_new(res, args[i]);
        res = my_strcat_new(res, " ");
    }
    res[my_strlen(res) - 1] = '\0';
    return (res);
}

void show_alias(alias_t *aliases, char *alias)
{
    for (; aliases; aliases = aliases->next) {
        if (str_compare(aliases->alias_name, alias)) {
            my_printf("%s\n", aliases->alias_do);
            return;
        }
    }
}