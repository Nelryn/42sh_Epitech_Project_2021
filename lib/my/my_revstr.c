/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** reverse the str
*/

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    int a = 0;
    int c;
    int i = my_strlen(str) - 1;

    while ( a < i ) {
        c = str[a];
        str[a] = str[i];
        str[i] = c;
        a++;
        i--;
    }
    return (str);
}
