/*
** EPITECH PROJECT, 2021
** get_append.c
** File description:
** get_append
*/

#include "my.h"

char *get_str_append(char *str)
{
    int i = 0;
    char *tmp = my_strdup(str);
    for (; str[i] != '%' && str[i] != '\0'; i++) {
        tmp[i] = str[i];
    }
    tmp[i] = '\0';
    return (tmp);
}

int get_len_append(char *str)
{
    int i = 0;

    for (; str[i] != '%' && str[i] != '\0'; i++) {
    }
    return (i);
}

char *append_nbr(int nb, char *res)
{
    char *nchar = int_to_char(nb);
    res = my_strcat_new(res, nchar);
    free(nchar);
    return (res);
}

char *append_char(char c, char *res)
{
    char *n = malloc(sizeof(char) * 2);
    n[0] = c;
    n[1] = '\0';
    res = my_strcat_new(res, n);
    free(n);
    return (res);
}

char *append_str(char *str, char *res)
{
    res = my_strcat_new(res, str);
    return (res);
}