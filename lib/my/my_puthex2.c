/*
** EPITECH PROJECT, 2020
** my_puthex2
** File description:
** uppercase
*/

#include "my.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

int my_puthex2(int k, int nb)
{
    int i = 1;

    while (i <= k) {
        i = i * 16;
    }
    i = i / 16;
    while (i != 0) {
        if (k / i > 9 && k / i < 16)
            my_putchar(k / i + 55);
        else
            my_putchar(k / i + 48);
        nb++;
        k = k % i;
        i = i / 16;
    }
    return (nb);
}
