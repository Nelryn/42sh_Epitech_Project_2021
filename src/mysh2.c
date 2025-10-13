/*
** EPITECH PROJECT, 2021
** B-PSU-210-RUN-2-1-minishell2-hugo.baret
** File description:
** mysh2
*/

#include "my.h"

char *cpy(char *str, int i)
{
    char *new = malloc(sizeof(char) * (my_strlen(str)));
    int a = 0;

    for (; str[i]; i++, a++)
        new[a] = str[i];
    new[a] = '\0';
    return new;
}

int check_c_d(char *str, char c)
{
    for (int i = 0; str[i]; i++) {
        if (i < my_strlen(str) && str[i] == c && str[i + 1] == c)
            return 1;
    }
    return 0;
}

int check_c_s(char *str, char c)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == c)
            return 1;
    }
    return 0;
}

int check(char *cmd)
{
    if (check_c_s(cmd, ';') || check_c_s(cmd, '>') || check_c_s(cmd, '<') ||
    check_c_d(cmd, '>') || check_c_s(cmd, '|') ||
    my_strncmp("repeat", cmd, 5) || check_c_d(cmd, '&'))
        return 1;
    return 0;
}

void mysh2(shell_t *shell, char *cmd)
{
    shell->buf = my_str_to_word_array(cmd, ';');
    for (int i = 0; shell->buf[i]; i++) {
        if (shell->buf[i][my_strlen(shell->buf[i])] == '\0' &&
        shell->buf[i][my_strlen(shell->buf[i]) - 1] == ' ')
            shell->buf[i][my_strlen(shell->buf[i]) - 1] = '\0';
    }
    for (int i = 0; shell->buf[i]; i++) {
        if (check(shell->buf[i])) {
            parse_cmd(shell, i);
        } else
            mysh1(shell, shell->buf[i], 1);
    }
}