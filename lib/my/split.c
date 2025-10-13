/*
** EPITECH PROJECT, 2021
** B-CPE-201-RUN-2-1-bscorewar-hugo.baret
** File description:
** split
*/

#include "my.h"

int tab_length(char *str, char *sep)
{
    int len = 0;
    char *tmp = NULL;

    tmp = my_strdup(str);
    while (strtok_r(tmp, sep, &tmp) != NULL)
        len++;
    return len;
}

char **split(char *str, char *sep)
{
    int i = 0;
    char **arr = NULL;
    int len = tab_length(str, sep);

    arr = malloc(sizeof(char *) * (len + 1));
    if (arr == NULL)
        return (NULL);
    for (; i < len; i++)
        arr[i] = strtok_r(str, sep, &str);
    arr[i] = NULL;
    return arr;
}