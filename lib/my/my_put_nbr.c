/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** displays the number given as a parameter
*/

#include <stdio.h>

void my_putchar(char c);

long long int my_put_nbr(long long int nbr)
{
    long long int x = 1;
    long long int nb = 0;

    if (nbr < 0) {
        nbr = nbr * (-1);
        my_putchar('-');
    }
    while ((nbr / x) >= 10) {
        x *= 10;
    }
    while (x > 0) {
        my_putchar((nbr / x) % 10 + '0');
        x /= 10;
        nb++;
    }
    return (nb);
}