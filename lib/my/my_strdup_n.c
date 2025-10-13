/*
** EPITECH PROJECT, 2021
** B-PSU-101-RUN-1-1-minishell1-hugo.baret
** File description:
** my_strdup_n
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup_n(char const *src, int n)
{
    char *dest;

    dest = malloc(sizeof(char) * (n + 1));
    dest = my_strncpy(dest, src, n);
    dest[n + 1] = '\0';
    return (dest);
}