/*
** EPITECH PROJECT, 2021
** B-PSU-101-RUN-1-1-minishell1-hugo.baret
** File description:
** path
*/

#include "my.h"
#include <stdlib.h>

int get_space_for_alloc2(char *str)
{
    int i = 0;
    int line = 1;
    while (str[i]) {
        if (str[i] == ':' || str[i] == '\n') {
            line++;
        }
        i++;
    }
    return line;
}

char **put_in_array2(char *str, char **arg)
{
    int i = 0;
    int x = 0;
    int y = 0;

    for (; str[i]; i++, y++) {
        if (str[i] == ':' || str[i] == '\n') {
            arg[x][y] = '/';
            arg[x][y + 1] = '\0';
            x++;
            y = 0;
            i++;
        }
        arg[x][y] = str[i];
    }
    arg[x][y] = '\0';
    return arg;
}

char **cut(char *str)
{
    int a = 0;
    char *str2 = remove_spaces(str);
    int line = get_space_for_alloc2(str2);
    char **arg = malloc(sizeof(char *) * (line + 1));
    int x = my_strlen(str2);

    for (a = 0; a != line; a++)
        arg[a] = malloc(sizeof(char) * (x + 1));
    arg[a] = NULL;
    arg = put_in_array2(str2, arg);
    free(str2);
    return arg;
}

char **find_the_path(char **env, char **path)
{
    int i = 0;
    char *str = NULL;
    int z = 0;

    if (my_get_env(env, "PATH") == 1) {
        for (; !my_strncmp("PATH", env[i], 4); i++);
        z = my_strlen(env[i]);
        str = malloc(sizeof(char) * (z + 1));
        str = my_strcpy(str, env[i]);
        for (i = 0; i != 5; i++)
            str++;
    } else {
        str = malloc(sizeof(char) * 14);
        str = "/usr/bin:/bin";
    }
    path = my_str_to_word_array(str, ':');
    i = my_arrlen(path) - 1;
    for (i = 0; path[i]; i++)
        path[i] = my_strcat(path[i], "/");
    return (path);
}