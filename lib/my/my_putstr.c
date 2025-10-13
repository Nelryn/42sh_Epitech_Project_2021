/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** display the characters of a string
*/

void my_putchar(char c);

int my_putstr(char const *str)
{
    long long int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return (i);
}
