/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** concatenate two strings
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int a = 0;
    int x = my_strlen(dest);
    int z = my_strlen(src);
    char *dest2 = malloc(sizeof(char) * (x + z + 1));
    int o = 0;

    while (i != x) {
        dest2[i] = dest[i];
        i++;
    }
    for (i = 0; src[a] != '\0'; i++, a++)
        dest2[x + i] = src[a];
    dest2[x + i] = '\0';
    o = my_strlen(dest2);
    for (i = 0; i != o; i++)
        dest[i] = dest2[i];
    dest[i] = '\0';
    free(dest2);
    return (dest);
}
