/*
** EPITECH PROJECT, 2021
** B-PSU-210-RUN-2-1-42sh-emilie.baunifais
** File description:
** alias
*/

#ifndef ALIAS_H_
#define ALIAS_H_

#include "pipe.h"

typedef struct alias_s {
    char *alias_name;
    char *alias_do;
    struct alias_s *next;
} alias_t;

void alias(shell_t *shell);
void unalias(alias_t **aliases, shell_t *shell);
int does_alias_exist(alias_t *aliases, char *alias_name);
char *is_it_an_alias(alias_t *aliases, char *cmd);
void add_alias(alias_t **aliases, char *alias_name, char *alias_do);
void free_aliases(alias_t *alias);

#endif /* !ALIAS_H_ */
