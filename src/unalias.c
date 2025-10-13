/*
** EPITECH PROJECT, 2021
** B-PSU-210-RUN-2-1-42sh-emilie.baunifais
** File description:
** unalias
*/

#include "my.h"
#include "pipe.h"

void free_alias(alias_t *alias)
{
    free(alias->alias_do);
    free(alias->alias_name);
    free(alias);
    alias = NULL;
}

void remove_alias(alias_t **aliases, char *alias_to_rm)
{
    alias_t *tmp = *aliases;

    if (tmp == NULL)
        return;
    if (str_compare(tmp->alias_name, alias_to_rm)) {
        *aliases = tmp->next;
        free_alias(tmp);
        return;
    } else {
        for (; tmp; tmp = tmp->next) {
            if (tmp->next != NULL &&
            str_compare(tmp->next->alias_name, alias_to_rm)) {
                tmp->next = (tmp->next->next != NULL) ? tmp->next->next :
                NULL;
            }
        }
    }
}

void unalias(shell_t *shell)
{
    if (my_arrlen(shell->tmp) == 1)
        my_puterror("unalias: Too few arguments.\n");
    else {
        for (int i = 1; shell->tmp[i]; i++) {
            remove_alias(&shell->aliases, shell->tmp[i]);
        }
    }
}