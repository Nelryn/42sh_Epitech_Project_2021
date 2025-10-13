/*
** EPITECH PROJECT, 2021
** B-PSU-210-RUN-2-1-42sh-emilie.baunifais
** File description:
** alias
*/

#include "my.h"
#include "pipe.h"

void remplace_alias(alias_t **aliases, char *new_do, char *alias)
{
    alias_t *tmp = *aliases;

    for (; tmp; tmp = tmp->next) {
        if (str_compare(tmp->alias_name, alias)) {
            tmp->alias_do = my_strdup(new_do);
            return;
        }
    }
}

int does_alias_exist(alias_t *aliases, char *alias_name)
{
    if (aliases == NULL)
        return (0);
    for (; aliases; aliases = aliases->next) {
        if (str_compare(aliases->alias_name, alias_name))
            return (1);
    }
    return (0);
}

void add_alias(alias_t **aliases, char *alias_name, char *alias_do)
{
    alias_t *new = malloc(sizeof(alias_t));

    new->alias_do = my_strdup(alias_do);
    new->alias_name = my_strdup(alias_name);
    new->next = *aliases;
    *aliases = new;
}

void show_aliases(alias_t *aliases)
{
    for (; aliases; aliases = aliases->next) {
        my_printf("%s\t%s\n", aliases->alias_name, aliases->alias_do);
    }
}

void alias(shell_t *shell)
{
    char *alias_do = NULL;
    if (my_arrlen(shell->tmp) == 1) {
        show_aliases(shell->aliases);
        return;
    }
    if (my_arrlen(shell->tmp) == 2) {
        if (does_alias_exist(shell->aliases, shell->tmp[1]))
            show_alias(shell->aliases, shell->tmp[1]);
        return;
    }
    alias_do = get_alias_do(shell->tmp);
    if (does_alias_exist(shell->aliases, shell->tmp[1]))
        remplace_alias(&shell->aliases, alias_do, shell->tmp[1]);
    else
        add_alias(&shell->aliases, shell->tmp[1], alias_do);
}