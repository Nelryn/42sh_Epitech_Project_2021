/*
** EPITECH PROJECT, 2020
** display5
** File description:
** fifth display
*/

#include "my.h"
#include <stdarg.h>

long long int display5(long long int nb, char const *format, va_list ap)
{
    if (format[1] == 'b')
        nb = my_putb(va_arg(ap, int), nb);
    else if (format[1] == 'l' && (format[2] == 'd' || format[2] == 'i'))
        nb = my_put_nbr(va_arg(ap, long int));
    else
        display6(nb, format, ap);
    return (nb);
}
