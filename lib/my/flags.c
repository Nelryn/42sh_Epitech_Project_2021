/*
** EPITECH PROJECT, 2020
** flags
** File description:
** flags
*/

int flags(char const *format)
{
    if (format[1] == 's' || format[1] == 'c' || format[1] == 'd' ||
        format[1] == 'o' || format[1] == 'C' || format[1] == 'i')
        return 1;
    if (format[1] == '%' || format[1] == 'S' || format[1] == 'x' ||
        format[1] == 'X' || format[1] == 'b' || format[1] == 'l' &&
        (format[2] == 'd' || format[2] == 'i') || format[1] == 'l' &&
        format[2] == 'l' && (format[3] == 'i' || format[3] == 'd'))
        return 1;
    return 0;
}
