/*
** EPITECH PROJECT, 2021
** B-PSU-210-RUN-2-1-minishell2-hugo.baret
** File description:
** mysh
*/

#include "my.h"

void mysh1(shell_t *shell, char *cmd, int pipe)
{
    shell->tmp = my_str_to_word_array(cmd, ' ');
    fun_or_builtin(shell, pipe);
}

void get_out(char **buf)
{
    if (buf == NULL)
        exit(0);
    int nb = (my_arrlen(buf) >= 2) ? my_getnbr(buf[1]) : 0;
    (isatty(0) == 1) ? my_printf("exit\n") : 0;
    exit(nb);
}

char **make_env(char **env_dup, char **env)
{
    int line = 0;
    int i = 0;

    if (env == NULL)
        return NULL;
    line = my_arrlen(env);
    env_dup = malloc(sizeof(char *) * (line + 1));
    for (i = 0; env[i] != NULL; i++)
        env_dup[i] = my_strdup(env[i]);
    env_dup[i] = NULL;
    return (env_dup);
}

void handle_status(int status)
{
    int sig = 0;

    if (WIFSIGNALED(status)) {
        sig = WTERMSIG(status);
        switch(sig) {
            case SIGFPE: write(2, "Floating exception", 18); break;
            case SIGABRT: write(2, "Abort", 5); break;
            case SIGSEGV: write(2, "Segmentation fault", 18); break;
            case SIGBUS: write(2, "Bus error", 9); break;
            default: break;
        }
        if (WCOREDUMP(status))
            write(2, " (core dumped)\n", 15);
        else
            write(2, "\n", 1);
    }
}

int mysh(shell_t *shell)
{
    size_t size = 0;
    char *cmd = NULL;
    int err = 0;

    while (42) {
        if (isatty(0) == 1)
            my_printf("$> ");
        err = getline(&cmd, &size, stdin);
        if (err == -1)
            exit(shell->r_value);
        if (!check(cmd))
            mysh1(shell, cmd, 1);
        else
            mysh2(shell, cmd);
    }
    free(cmd);
    cmd = NULL;
    return 0;
}