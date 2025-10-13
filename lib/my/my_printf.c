/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** my_printf
*/

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"

long long int display3(long long int nb, char const *format, va_list ap)
{
    if (format[1] == '%') {
        my_putchar(format[1]);
        nb++;
    } else if (format[1] == 'S')
        nb = flags2(va_arg(ap, char *), nb);
    else
        nb = display4(nb, format, ap);
    return (nb);
}

long long int my_put_octet(int nbr, long long int nb)
{
    int x = 8;

    while ((nbr / x) >= 8) {
        x *= 8;
    }
    while (x > 0) {
        if (nbr >= 10)
            my_putchar((nbr / x) % 8 + '0');
        else {
            x /= 8;
            my_putchar((nbr / x) % 8 + '0');
        }
        x /= 8;
        nb++;
    }
    return (nb);
}

long long int display2(char const *format, va_list ap, long long int nb)
{
    if (format[1] == 'c' || format[1] == 'C') {
        my_putchar(va_arg(ap, int));
        nb = nb + 1;
    } else if (format[1] == 'o')
        nb = my_put_octet(va_arg(ap, int), nb);
    else
        nb = display3(nb, format, ap) + nb;
    return (nb);
}

long long int display(char const *format, va_list ap, long long int nb)
{
    if (format[1] == 's')
        nb = my_putstr(va_arg(ap, char *));
    else if (format[1] == 'd' || format[1] == 'i') {
        nb = my_put_nbr(va_arg(ap, int));
    } else
        nb = display2(format, ap, nb) + nb;
    return (nb);
}

long long int my_printf(char const *format, ...)
{
    va_list ap;
    long long int nb = 0;
    va_start(ap, format);
    for (;format[0] != '\0'; format++) {
        if (format[0] == '%') {
            if (flags(format) == 1) {
                nb = display(format, ap, nb) + nb;
                if (format[1] == 'l') {
                    format++;
                    (format[1] == 'l') ? format++ : 0;
                }
                format++;
            }
        } else {
            my_putchar(format[0]);
            nb++;
        }
    }
    va_end(ap);
    return (nb);
}
