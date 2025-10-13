/*
** EPITECH PROJECT, 2021
** B-PSU-210-RUN-2-1-42sh-emilie.baunifais
** File description:
** freedom
*/

#include "my.h"

void free_list(shell_t *shell)
{
    for (; shell->aliases != NULL; shell->aliases = shell->aliases->next) {
        free(shell->aliases->alias_name);
        free(shell->aliases->alias_do);
    }
}

void free_all(shell_t *shell)
{
    free_array(shell->env);
    free_array(shell->buf);
    free_array(shell->tmp);
    free_list(shell);
    free(shell->aliases);
    free(shell);
}