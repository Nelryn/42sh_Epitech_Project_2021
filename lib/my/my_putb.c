/*
** EPITECH PROJECT, 2020
** my_putb
** File description:
** my_putb
*/

#include "my.h"

int my_putb(int nbr, int nb)
{
    int x = 2;

    while ((nbr / x) >= 2) {
        x *= 2;
    }
    while (x > 0) {
        my_putchar((nbr / x) % 2 + '0');
        x /= 2;
        nb++;
    }
    return (nb);
}
