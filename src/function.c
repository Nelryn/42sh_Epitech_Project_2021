/*
** EPITECH PROJECT, 2021
** B-PSU-101-RUN-1-1-minishell1-hugo.baret
** File description:
** find_the_path
*/

#include "my.h"

int check_exist(char **path, char **old_path, char **buf)
{
    struct stat s;
    int i = 0;

    while (old_path[i]) {
        *path = my_strcat(old_path[i], buf[0]);
        if (stat(*path, &s) != -1)
            return 1;
        i++;
    }
    if (stat(buf[0], &s) != -1) {
        *path = my_strdup(buf[0]);
        return 1;
    }
    return 0;
}

int ex_err(char **buf, char **path, char **str)
{
    if (!check_exist(str, path, buf) || my_arrlen(path) == 0) {
        write(2, buf[0], my_strlen(buf[0]));
        write(2, ": Command not found.\n", 21);
        if (isatty(0) == 0)
            exit(84);
        return (0);
    }
    return 1;
}

void check_exec(char *path, char **env, char **buf)
{
    if (execve(path, buf, env) == -1) {
        my_puterror(path);
        if (errno == ENOEXEC)
            my_puterror(": Exec format error. Wrong Architecture.\n");
        else if (errno == EACCES)
            my_puterror(": Permission denied.\n");
        exit(84);
    }
}

int function(shell_t *shell, int pipe)
{
    char **path2 = NULL;
    char *path = NULL;
    pid_t pid = getpid();

    path2 = find_the_path(shell->env, path2);
    if (!ex_err(shell->tmp, path2, &path)) {
        free_array(path2);
        return 0;
    }
    if (pipe == 1) {
        pid = fork();
        if (pid == 0)
            check_exec(path, shell->env, shell->tmp);
        else {
            waitpid(pid, &shell->r_value, WCONTINUED | WUNTRACED);
            handle_status(shell->r_value);
        }
    } else
        check_exec(path, shell->env, shell->tmp);
    free_array(path2);
    return 0;
}