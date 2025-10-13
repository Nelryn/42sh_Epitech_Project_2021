/*
** EPITECH PROJECT, 2021
** B-PSU-210-RUN-2-1-42sh-emilie.baunifais
** File description:
** redirection2
*/

#include "my.h"

void double_l_redirection(shell_t *shell, char **tmp)
{
    int fd = open("/tmp/mysh", O_RDONLY, 0664);
    int out = dup(STDIN_FILENO);
    if (fd == -1)
        return;
    dup2(fd, STDIN_FILENO);
    close(fd);
    mysh1(shell, tmp[0], 1);
    dup2(out, STDIN_FILENO);
    close(out);
    free_array(tmp);
}

void get_lines(shell_t *shell, int i, ssize_t rd)
{
    int fd = open("/tmp/mysh", O_CREAT | O_TRUNC | O_WRONLY, 0664);
    char *str = NULL;
    size_t size = 0;
    char **tmp = split(shell->buf[i], "<<");

    for (int z = 0; tmp[z] != NULL; z++)
        tmp[z] = clean_str(tmp[z]);
    if (fd == -1)
        return;
    while (1) {
        my_printf("? ");
        if ((rd = getline(&str, &size, stdin)) < 0)
            break;
        str[rd - 1] = '\0';
        if (!strcmp(str, tmp[1]))
            break;
        write(fd, str, strlen(str));
        write(fd, "\n", 1);
    }
    close(fd);
    double_l_redirection(shell, tmp);
}