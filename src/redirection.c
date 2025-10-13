/*
** EPITECH PROJECT, 2021
** B-PSU-210-RUN-2-1-minishell2-hugo.baret
** File description:
** redirection
*/

#include "my.h"

void double_r_redirection(shell_t *shell, int i)
{
    char **redirect = my_str_to_word_array(shell->buf[i], '>');
    int out = dup(STDOUT_FILENO);
    char *file = cpy(redirect[1], 2);
    redirect[my_arrlen(redirect) - 1] = NULL;
    int fd = open(file, O_CREAT | O_APPEND | O_WRONLY, 0666);

    if (fd == -1)
        return;
    redirect = removes(redirect);
    dup2(fd, STDOUT_FILENO);
    close(fd);
    mysh1(shell, redirect[0], 1);
    dup2(out, STDOUT_FILENO);
    close(out);
    free_array(redirect);
}

void simple_r_redirection(shell_t *shell, int i)
{
    char **redirect = my_str_to_word_array(shell->buf[i], '>');
    int out = dup(STDOUT_FILENO);
    char *file = cpy(redirect[1], 1);
    int fd = open(file, O_CREAT | O_TRUNC | O_WRONLY, 0666);

    if (fd == -1)
        return;
    redirect = removes(redirect);
    dup2(fd, STDOUT_FILENO);
    close(fd);
    mysh1(shell, redirect[0], 1);
    dup2(out, STDOUT_FILENO);
    close(out);
    free_array(redirect);
}

void simple_l_redirection(shell_t *shell, int i)
{
    char **redirect = my_str_to_word_array(shell->buf[i], '<');
    char *file = cpy(redirect[1], 1);
    int out = dup(STDIN_FILENO);
    int fd = open(file, O_RDONLY);

    if (fd == -1) {
        write(2, file, my_strlen(file));
        write(2, ": No such file or directory.\n", 29);
        return;
    }
    redirect = removes(redirect);
    dup2(fd, STDIN_FILENO);
    close(fd);
    mysh1(shell, redirect[0], 1);
    dup2(out, STDIN_FILENO);
    close(out);
    free_array(redirect);
}

void redirection(shell_t *shell, int i)
{
    if (check_c_d(shell->buf[i], '>')) {
        double_r_redirection(shell, i);
        return;
    }
    if (check_c_d(shell->buf[i], '<')) {
        get_lines(shell, i, 0);
        return;
    }
    if (check_c_s(shell->buf[i], '>'))
        simple_r_redirection(shell, i);
    if (check_c_s(shell->buf[i], '<'))
        simple_l_redirection(shell, i);
}