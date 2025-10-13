/*
** EPITECH PROJECT, 2021
** append
** File description:
** append
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

char *get_my_str(char **format, va_list list, char *res)
{
    if (format[0][1] == 'd')
        res = append_nbr(va_arg(list, int), res);
    if (format[0][1] == 'c')
        res = append_char(va_arg(list, int), res);
    if (format[0][1] == 's')
        res = append_str(va_arg(list, char *), res);
    if (format[0][1] == '%')
        res = append_percent(res);
    (*format) = (*format) + 2;
    return (res);
}

char *get_my_format(char **format, va_list list, char *res)
{
    char *tmp;
    int len = get_len_append(format[0]);
    tmp = get_str_append(format[0]);
    res = my_strcat_new(res, tmp);
    (*format) = (*format) + len;
    free((tmp));
    return (res);
}

char *append(char *format, ...)
{
    va_list list;
    char *res = malloc(sizeof(char) * 1);

    va_start(list, format);
    while (format[0] != '\0') {
        if (format[0] == '%')
            res = get_my_str(&format, list, res);
        else
            res = get_my_format(&format, list, res);
    }
    res[my_strlen(res)] = '\0';
    va_end(list);
    return (res);
}
