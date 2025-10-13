/*
** EPITECH PROJECT, 2021
** test
** File description:
** pipe
*/

#include "my.h"
#include "pipe.h"

char **make_pipe(char **pip, char **buf, int i)
{
    pip = my_str_to_word_array(buf[i], '|');
    for (int z = 0; pip[z]; z++) {
        if (pip[z][0] == ' ') {
            pip[z] = my_revstr(pip[z]);
            pip = removes(pip);
            pip[z] = my_revstr(pip[z]);
        }
    }
    return pip;
}

void in_loop(pipe_t *pipes, shell_t *shell, int i)
{
    pipe(pipes->fd);
    pipes->pid = fork();
    if (pipes->pid == 0) {
        dup2(pipes->backup, 0);
        if (pipes->pipe[i + 1] != NULL)
            dup2(pipes->fd[1], 1);
        close(pipes->fd[0]);
        mysh1(shell, pipes->pipe[i], 0);
    } else {
        if (pipes->pipe[i + 1] != NULL)
            waitpid(pipes->pid, NULL, WNOHANG);
        else
            waitpid(pipes->pid, NULL, 0);
        if (pipes->backup != 0)
            close(pipes->backup);
        close(pipes->fd[1]);
        pipes->backup = pipes->fd[0];
    }
}

void pipe_loop(shell_t *shell, int i)
{
    pipe_t pipes = {NULL, {0, 0}, 0, NULL, 0};

    pipes.pipe = make_pipe(pipes.pipe, shell->buf, i);
    for (int i = 0; pipes.pipe[i] != NULL; i++) {
        in_loop(&pipes, shell, i);
    }
    close(pipes.backup);
}