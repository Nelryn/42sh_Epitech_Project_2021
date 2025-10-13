/*
** EPITECH PROJECT, 2021
** int_to_char
** File description:
** int_to_char
*/

#include "my.h"

char *int_to_char(int nb)
{
    int i = 1;
    int n = 0;
    int len = 0;
    char *nchar;

    if (nb == 0) {
        nchar = malloc(sizeof(char) * 1);
        nchar[n] = '0';
        n++;
        return (nchar);
    }
    for (; i <= nb; i = i * 10)
        len++;
    i = i / 10;
    nchar = malloc(sizeof(char) * len);
    for (; i != 0; n++, nb = nb % i, i = i / 10)
        nchar[n] = nb / i + 48;
    nchar[n] = '\0';
    return (nchar);
}