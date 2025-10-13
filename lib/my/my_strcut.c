/*
** EPITECH PROJECT, 2021
** my_strcut.c
** File description:
** my_strcut
*/

#include <stddef.h>
#include "my.h"

char *my_strcut(char *str, char c)
{
    int i = 0;
    if (str == NULL)
        return (str);
    for (; str[i]; i++) {
        if (str[i] == c)
            break;
    }
    if (i == my_strlen(str))
        return (NULL);
    for (i = 0; str[i] && str[i] != c;)
        str++;
    str++;
    return (str);
}
