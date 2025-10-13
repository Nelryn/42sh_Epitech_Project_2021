/*
** EPITECH PROJECT, 2020
** display4
** File description:
** fourth display
*/

#include <stdarg.h>
#include "my.h"

long long int display4(long long int nb, char const *format, va_list ap)
{
    if (format[1] == 'x')
        nb = my_puthex(va_arg(ap, int), nb);
    else if (format[1] == 'X')
        nb = my_puthex2(va_arg(ap, int), nb);
    else
        nb = display5(nb, format, ap);
    return (nb);
}
