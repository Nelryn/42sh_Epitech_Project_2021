/*
** EPITECH PROJECT, 2021
** B-PSU-101-RUN-1-1-bsminishell1-hugo.baret
** File description:
** my_str_to_word_array
*/

#include "my.h"

int get_space_for_alloc(char *str, char sep)
{
    int i = 0;
    int line = 1;
    while (str[i]) {
        if (str[i] == sep || str[i] == '\n') {
            line++;
        }
        i++;
    }
    return line;
}

char **put_in_array(char *str, char **arg, char sep)
{
    int i = 0;
    int x = 0;
    int y = 0;

    for (; str[i]; i++, y++) {
        if (str[i] == sep || str[i] == '\n') {
            arg[x][y] = '\0';
            x++;
            y = 0;
            i++;
        }
        arg[x][y] = str[i];
    }
    arg[x][y] = '\0';
    return arg;
}

char *loop(char *str, char *str2)
{
    int a = 0;
    int i = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == '\t')
            str[i] = ' ';
    }
    for (; str[i]; i++) {
        if (str[i] == ' ') {
            for (; str[i + 1] == ' '; i++);
            (str[i + 1] != '\n') ? str2[a] = str[i], a++ : 0;
        } else if (str[i] == '\n')
            break;
        else {
            str2[a] = str[i];
            a++;
        }
    }
    str2[a] = '\0';
    return (str2);
}

char *remove_spaces(char *str)
{
    char *str2 = malloc(sizeof(char) * (my_strlen(str) + 1));

    for (; str[0] == ' ' || str[0] == '\t'; str++);
    str2 = loop(str, str2);
    return (str2);
}

char **my_str_to_word_array(char *str, char sep)
{
    int a = 0;
    char *str2 = remove_spaces(str);
    int line = get_space_for_alloc(str2, sep);
    char **arg = malloc(sizeof(char *) * (line + 1));

    for (a = 0; a != line; a++)
        arg[a] = malloc(sizeof(char) * (my_strlen(str2) + 1));
    arg[a] = NULL;
    arg = put_in_array(str2, arg, sep);
    free(str2);
    return arg;
}