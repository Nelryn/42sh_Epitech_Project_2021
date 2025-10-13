/*
** EPITECH PROJECT, 2021
** B-PSU-210-RUN-2-1-minishell2-hugo.baret
** File description:
** parse
*/

#include "my.h"

int redirect(char *cmd, int r, int p)
{
    for (int i = 0; cmd[i]; i++) {
        (cmd[i] == '<' || cmd[i] == '>') ? r++ : 0;
        (cmd[i] == '|') ? p++ : 0;
    }
    if (p != 0)
        return 0;
    return 1;
}

int pipes(char *cmd, int r, int p)
{
    for (int i = 0; cmd[i]; i++) {
        (cmd[i] == '<' || cmd[i] == '>') ? r++ : 0;
        (cmd[i] == '|') ? p++ : 0;
    }
    if (r != 0)
        return 0;
    return 1;
}

int parse_cmd2(shell_t *shell, int i)
{
    if (check_c_d(shell->buf[i], '&')) {
        and(shell, i);
        return (1);
    }
    if (check_c_d(shell->buf[i], '|')) {
        or(shell, i);
        return (1);
    }
    return (0);
}

void parse_cmd(shell_t *shell, int i)
{
    int r = 0;
    int p = 0;

    if (parse_cmd2(shell, i) == 1)
        return;
    if (!strncmp(shell->buf[i], "repeat", 5)) {
        repeat(shell, i);
        return;
    }
    if (redirect(shell->buf[i], r, p)) {
        redirection(shell, i);
        return;
    }
    if (pipes(shell->buf[i], r, p)) {
        pipe_loop(shell, i);
        return;
    }
}