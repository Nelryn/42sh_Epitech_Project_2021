/*
** EPITECH PROJECT, 2021
** B-PSU-210-RUN-2-1-42sh-emilie.baunifais
** File description:
** mix_tabs
*/

#include "my.h"

char **mix_tabs(char **old, char **new)
{
    char **res = malloc(sizeof(char *) * (my_arrlen(old) + my_arrlen(new) + 1));
    int i = 0;

    for (int j = 0; new[j]; j++, i++) {
        res[i] = my_strdup(new[j]);
    }
    for (int j = 1; old[j]; j++, i++) {
        res[i] = my_strdup(old[j]);
    }
    res[i] = NULL;
    return (res);
}