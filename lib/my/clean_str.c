/*
** EPITECH PROJECT, 2021
** B-PSU-101-RUN-1-1-minishell1-emilie.baunifais
** File description:
** clean_str
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *remove_jump(char *dest, char *src)
{
    int i = 0;

    while (src[i] != '\0') {
        if (src[i] == '\n') {
            i++;
            dest[i - 1] = '\0';
        } else {
            dest[i] = src[i];
            i++;
        }
    }
    dest[i] = '\0';
    return dest;
}

char *clean_tab(char *buff)
{
    int i = 0;
    char *s = malloc(sizeof(char) * (my_strlen(buff) + 1));

    s = remove_jump(s, buff);
    while (s[i] != '\0') {
        if (s[i] == '\t')
            s[i] = ' ';
        i++;
    }
    s[i] = '\0';
    return s;
}

int skip_spaces(char *buff, int index)
{
    while (buff[index] == ' ') {
        index++;
    }
    return index;
}

int get_size(char *s)
{
    int index = 0;
    int size = 0;

    index = skip_spaces(s, index);
    while (s[index] != '\0') {
        if (s[index] != ' ')
            size++;
        if (s[index] == ' ' && s[index + 1] != ' ' && s[index + 1] != '\0')
            size++;
        index++;
    }
    return size;
}

char *clean_str(char *buff)
{
    int index = 0;
    int copy = 0;
    char *s = clean_tab(buff);
    char *cleaned = malloc(sizeof(char) * (get_size(s) + 1));

    if (get_size(s) == 0 && skip_spaces(s, index) == my_strlen(s)) {
        cleaned[0] = ' ';
        copy++;
    }
    index = skip_spaces(s, index);
    while (s[index] != '\0') {
        (s[index] != ' ') ? cleaned[copy] = s[index], copy++ : 0;
        if (s[index] == ' ' && s[index + 1] != ' ' && s[index + 1] != '\0') {
            cleaned[copy] = s[index];
            copy++;
        }
        index++;
    }
    free(s);
    cleaned[copy] = '\0';
    return cleaned;
}