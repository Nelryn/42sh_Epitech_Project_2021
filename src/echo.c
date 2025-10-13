/*
** EPITECH PROJECT, 2021
** echo.c
** File description:
** echo
*/

#include "my.h"

void display_str(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] != 34 && str[i] != 92 && str[i] != 10)
            write (1, &str[i], 1);
        i = i + 1;
    }
}

void display_path(char **env)
{
    int i = 0;
    int j = 5;

    while (env[i] != NULL) {
        if (my_strncmp("PATH=", env[i], 5))
            break;
        i = i + 1;
    }
    while (env[i][j] != '\0') {
        (env[i][j] != ':') ? write (1, &env[i][j], 1) : 0;
        (env[i][j] == ':') ? write (1, " ", 1) : 0;
        j = j + 1;
    }
}

int compare_echo(shell_t *shell, int i)
{
    if (str_compare(shell->tmp[i], "$path")) {
        display_path(shell->env);
        return (0);
    }
    if (str_compare(shell->tmp[i], "$?")) {
        my_printf("%d", WEXITSTATUS(shell->r_value));
        shell->r_value = 0;
        return (0);
    }
    return (1);
}

int execute_echo(shell_t *shell)
{
    int i = 1;
    size_t size = 0;
    char *cmd = NULL;
    int err = -1;

    while (shell->tmp[i] != NULL) {
        if (shell->tmp[i][my_strlen(shell->tmp[i]) - 1] == 92) {
            my_printf("? ");
            err = getline(&cmd, &size, stdin);
        }
        (compare_echo(shell, i) == 1) ? display_str(shell->tmp[i]) : 0;
        if (err != -1) {
            write (1, " ", 1);
            display_str(cmd);
        }
        i = i + 1;
        (shell->tmp[i] != NULL) ? write (1, " ", 1) : 0;
    }
    write (1, "\n", 1);
    return (0);
}