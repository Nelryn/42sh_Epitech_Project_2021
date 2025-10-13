/*
** EPITECH PROJECT, 2021
** B-PSU-210-RUN-2-1-minishell2-hugo.baret
** File description:
** other_fun
*/

#include "my.h"

void and(shell_t *shell, int i)
{
    char **cmd = NULL;

    cmd = split(shell->buf[i], "&&");
    for (int i = 0; cmd[i]; i++)
        cmd[i] = clean_str(cmd[i]);
    for (int i = 0; cmd[i]; i++) {
        mysh1(shell, cmd[i], 1);
        if (WEXITSTATUS(shell->r_value) != 0)
            break;
    }
}

void or(shell_t *shell, int i)
{
    char **cmd = NULL;

    cmd = split(shell->buf[i], "||");
    for (int i = 0; cmd[i]; i++)
        cmd[i] = clean_str(cmd[i]);
    for (int i = 0; cmd[i]; i++) {
        mysh1(shell, cmd[i], 1);
        if (WEXITSTATUS(shell->r_value) == 0)
            break;
    }
}

void repeat(shell_t *shell, int i)
{
    char **tmp = NULL;
    int lap = 0;

    tmp = my_str_to_word_array(shell->buf[i], ' ');
    if (!str_compare(tmp[0], "repeat")) {
        write(2, tmp[0], strlen(tmp[0]));
        write(2,  ": Command not found.\n", 21);
        shell->r_value = 511;
        return;
    }
    if (my_arrlen(tmp) < 3) {
        write(2, "repeat: Too few arguments.\n", 27);
        return;
    } else if (my_str_isnum(tmp[1]) == 1) {
        write(2, "repeat: Badly formed number.\n", 29);
        return;
    }
    lap = atoi(tmp[1]);
    shell->buf[i] += 9;
    for (int j = 0; j != lap; j++)
        mysh1(shell, shell->buf[i], 1);
}

char **removes(char **redirect)
{
    for (int z = 0; redirect[z]; z++) {
        if (redirect[z][my_strlen(redirect[z])] == '\0' &&
        redirect[z][my_strlen(redirect[z]) - 1] == ' ')
            redirect[z][my_strlen(redirect[z]) - 1] = '\0';
    }
    return redirect;
}