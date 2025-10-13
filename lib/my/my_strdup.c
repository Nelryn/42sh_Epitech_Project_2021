/*
** EPITECH PROJECT, 2020
** my_strdup
** File description:
** my_strdup
*/

#include "my.h"

char *my_strdup(char const *src)
{
    char *dest;

    dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    my_strcpy(dest, src);
    return (dest);
}

