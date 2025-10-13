/*
** EPITECH PROJECT, 2020
** flag_s
** File description:
** flags s
*/

#include "my.h"
#include <stdarg.h>

long long int my_put_octet1(long long int nb, char const *str, int i)
{
    int  nbr = str[i];
    int x = 8;

    while ((nbr / x) >= 8) {
        x *= 8;
    }
    while (x > 0) {
        if (nbr >= 10)
            my_putchar((nbr / x) % 8 + '0');
        else {
            x /= 8;
            my_putchar((nbr/x) % 8 + '0');
        }
        x /= 8;
        nb++;
    }
    return (nb);
}

int zero(char x, int nb)
{

    if (x < 10) {
        my_putstr("00");
        nb = nb + 2;
    } else if (x < 100 && x >= 10) {
        my_putchar('0');
        nb++;
    }
    return (nb);
}

int flags2(char const *str, int nb)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < 32 || str[i] >= 127) {
            my_putchar('\\');
            zero(str[i], nb);
            nb = my_put_octet1(nb, str, i);
        } else {
            my_putchar(str[i]);
            nb++;
        }
        i++;
    }
    return (nb);
}
