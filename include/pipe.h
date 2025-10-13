/*
** EPITECH PROJECT, 2021
** B-PSU-210-RUN-2-1-minishell2-hugo.baret
** File description:
** pipe
*/

#ifndef PIPE_H_
#define PIPE_H_

typedef struct pipe_s {
    char **pipe;
    int fd[2];
    int backup;
    char *path;
    int pid;
} pipe_t;

typedef struct alias_s {
    char *alias_name;
    char *alias_do;
    struct alias_s *next;
} alias_t;

typedef struct shell_s {
    char **env;
    char **buf;
    char **tmp;
    int r_value;
    alias_t *aliases;
} shell_t;

void alias(shell_t *shell);
void unalias(shell_t *shell);
int does_alias_exist(alias_t *aliases, char *alias_name);
char **is_it_an_alias(alias_t *aliases, char *cmd);
void add_alias(alias_t **aliases, char *alias_name, char *alias_do);
void free_aliases(alias_t *alias);
void show_alias(alias_t *aliases, char *alias);
char *get_alias_do(char **args);
char *my_strcut(char *str, char c);
char *my_revcut(char *str, char c);
char *my_firstcut(char *str, char c);

#endif /* !PIPE_H_ */
