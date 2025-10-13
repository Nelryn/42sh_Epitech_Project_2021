/*
** EPITECH PROJECT, 2021
** B-CPE-200-RUN-2-1-matchstick-hugo.baret
** File description:
** alloc
*/

#include "my.h"

char **my_array_alloc(char **arr, int cols, int rows)
{
    int i = 0;

    arr = malloc(sizeof(char *) * (rows + 1));
    for (i = 0; i != rows; i++)
        arr[i] = malloc(sizeof(char) * (cols + 1));
    arr[i] = NULL;
    return (arr);
}

char *my_str_alloc(char *str, int cols)
{
    str = malloc(sizeof(char) * (cols + 1));
    return (str);
}