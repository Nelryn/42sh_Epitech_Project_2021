/*
** EPITECH PROJECT, 2021
** get_append2
** File description:
** get_append2
*/

#include "my.h"

char *append_percent(char *res)
{
    char *p = malloc(sizeof(char) * 2);
    p[0] = '%';
    p[1] = '\0';
    res = my_strcat_new(res, p);
    free(p);
    return (res);
}