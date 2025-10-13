/*
** EPITECH PROJECT, 2021
** B-PSU-210-RUN-2-1-42sh-emilie.baunifais
** File description:
** get_alias
*/

#include "my.h"
#include "pipe.h"

char *get_alias(alias_t *aliases, char *alias_to_get)
{
    char *str = NULL;
    for (; aliases; aliases = aliases->next) {
        if (str_compare(my_firstcut(aliases->alias_name, ' '),
        my_firstcut(alias_to_get, ' '))) {
            str = my_strcat_new(aliases->alias_do, " ");
            str = my_strcat_new(str, my_strcut(alias_to_get, ' '));
            return (clean_str(str));
        }
    }
    return (NULL);
}

char **is_it_an_alias(alias_t *aliases, char *cmd)
{
    alias_t *alias_found = NULL;

    if (!does_alias_exist(aliases, my_firstcut(cmd, ' ')))
        return (my_str_to_word_array(cmd, ' '));
    else {
        while (does_alias_exist(aliases, my_firstcut(cmd, ' '))) {
            cmd = get_alias(aliases, cmd);
            if (does_alias_exist(alias_found, my_firstcut(cmd, ' '))) {
                my_printf("Alias loop.\n");
                return (NULL);
            } else
                add_alias(&alias_found, my_firstcut(cmd, ' '), cmd);
        }
    }
    return (my_str_to_word_array(cmd, ' '));
}