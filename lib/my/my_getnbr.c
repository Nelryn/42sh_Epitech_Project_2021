/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** return a nb
*/

int minus(char const *str, int *i)
{
    int count = 0;

    while (str[*i] != '\0' && (str[*i] == '-' || str[*i] == '+')) {
        if (str[*i] == '-') {
            count++;
        }
        (*i)++;
    }
    return (count);
}

int my_getnbr(char const *str)
{
    int i = 0;
    int nb = 0;
    int count = minus(str, &i);

    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            nb = (str[i]) - 48 + nb * 10;
        } else
            break;
        i++;
    }
    count = count % 2;
    if (count == 1)
        nb = nb * (-1);
    return (nb);
}
