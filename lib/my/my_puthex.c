/*
** EPITECH PROJECT, 2020
** my_puthex
** File description:
** put some hex
*/

#include "my.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

int my_puthex(int k, long long int nb)
{
    int i = 1;

    while (i <= k) {
        i = i * 16;
    }
    i = i / 16;
    while (i != 0) {
        if (k / i > 9 && k / i < 16)
            my_putchar(k / i + 87);
        else
            my_putchar(k / i + 48);
        nb++;
        k = k % i;
        i = i / 16;
    }
    return (nb);
}
