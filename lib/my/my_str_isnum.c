/*
** EPITECH PROJECT, 2020
** my_str_isnum
** File description:
** my_str_isnum
*/

#include "my.h"

int is_num(char c)
{
    return (c >= '0' && c <= '9');
}

int my_str_isnum2(char const *str)
{
    if (str[0] == '\n')
        return 0;
    for (int i = 0; str[i]; i++) {
        if (!(is_num(str[i]) || str[i] == '\n'))
            return 0;
    }
    return 1;
}

int my_str_isnum(char const *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] < '0' || str[i] > '9')
            return 1;
    }
    return 0;
}
