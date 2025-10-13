/*
** EPITECH PROJECT, 2020
** display6
** File description:
** display6
*/

#include <stdarg.h>
#include "my.h"

long long int display6(long long int nb, char const *format, va_list ap)
{
    if (format[1] == 'l' && format[2] == 'l' && (format[3] == 'i' ||
    format[3] == 'd'))
        my_put_nbr(va_arg(ap, long long int));
    return (nb);
}
