/*
** EPITECH PROJECT, 2021
** B-PSU-210-RUN-2-1-minishell2-hugo.baret
** File description:
** cd_error
*/

#include "my.h"

void cd_error(char *tmp, shell_t *shell)
{
    struct stat s;

    if (stat(tmp, &s) == -1) {
        write(2, tmp, my_strlen(tmp));
        write(2, ": No such file or directory.\n", 29);
        shell->r_value = 511;
    } else {
        write(2, tmp, my_strlen(tmp));
        write(2, ": Not a directory.\n", 19);
        shell->r_value = 511;
    }
}
