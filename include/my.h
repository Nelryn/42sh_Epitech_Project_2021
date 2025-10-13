/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** prototypes for functions
*/

#ifndef MY_H_
#define MY_H_
#define BLANK (str[i] == ' ' && str[i + 1] != ' ' && \
        str[i + 1] != '\n' || str[i] == '\t' && \
        str[i + 1] != '\t' && str[i + 1] != '\n')

#define UNUSED __attribute__((unused))

#include <signal.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include "pipe.h"

char **mix_tabs(char **old, char **new);
char *my_strcat_new(char *dest, char *src);
char *append_percent(char *res);
char *append_str(char *str, char *res);
char *append_char(char c, char *res);
char *append_nbr(int nb, char *res);
char *append(char *format, ...);
int get_len_append(char *str);
char *get_str_append(char *str);
char *int_to_char(int nb);
int function(shell_t *shell, int pipe);
void make_cd(shell_t *shell);
char **split(char *str, char *sep);
void get_out(char **buf);
void repeat(shell_t *shell, int i);
int isatty_sh(char **env, char **buf);
void and(shell_t *shell, int i);
char *clean_str(char *buff);
void fun_or_builtin(shell_t *shell, int pipe);
char **make_unsetenv(shell_t *shell);
char **find_the_path(char **env, char **path);
char *remove_spaces(char *str);
char **make_setenv(shell_t *shell);
char *loop(char *str, char *str2);
char **make_env(char **env_dup, char **env);
int check(char *cmd);
int check_c_s(char *str, char c);
void mysh1(shell_t *shell, char *cmd, int pipe);
void mysh2(shell_t *shell, char *cmd);
void handle_status(int status);
void redirection(shell_t *shell, int i);
char *cpy(char *str, int i);
char **removes(char **redirect);
int check_c_d(char *str, char c);
void pipe_loop(shell_t *shell, int i);
int ex_err(char **buf, char **path, char **str);
void parse_cmd(shell_t *shell, int i);
void some_where(shell_t *shell, int save);
int check_builtin(char *cmd);
void cd_error(char *tmp, shell_t *shell);
void which_one(shell_t *shell);
int execute_echo(shell_t *shell);
void display_str(char *str);
void display_path(char **env);
int compare_echo(shell_t *shell, int i);
int mysh(shell_t *shell);
int cd_home_and_previous(shell_t *shell, char *path);
void set_old_pwd(char *path, shell_t *shell);
void set_new_pwd(char *path, shell_t *shell);
char *get_old_pwd(char **env);
void get_lines(shell_t *shell, int i, ssize_t size);
void or (shell_t * shell, int i);
char **make_setenv2(shell_t *shell, int i, int count, char **tmp_env);
char **cond1(char **env, char **buf, int i, int count);
char **cond2(char **env, char **buf, int i, int count);
void free_all(shell_t *shell);

void redirect_all_stdout(void);

void print_arr(char **arr);

int my_arrlen(char **arr);

char **my_array_alloc(char **arr, int cols, int rows);

char *my_str_alloc(char *str, int cols);

void free_array(char **arr);

long long int display6(long long int nb, char const *format, va_list ap);

int str_compare(char *str1, char *str2);

int my_isalpha(char c);

char *my_strdup(char const *str);

char *my_strdup_n(char const *src, int n);

long long int my_printf(char const *format, ...);

int my_putb(int b, int nb);

int my_puthex(int k, long long int nb);

int my_puthex2(int k, int nb);

long long int display4(long long int nb, char const *format, va_list ap);

long long int display5(long long int nb, char const *format, va_list ap);

int octet(int oct);

int flags2(char const *str, int nb);

long long int my_put_octet(int nbr, long long int nb);

int flags(char const *format);

void my_putchar(char c);

int my_isneg(int nb);

long long int my_put_nbr(long long int nb);

void my_swap(int *a, int *b);

int my_putstr(char const *str);

int my_strlen(char const *str);

int my_getnbr(char const *str);

void my_sort_int_array(int *tab, int size);

int my_compute_power_rec(int nb, int power);

int my_compute_square_root(int nb);

int my_is_prime(int nb);

int my_find_prime_sup(int nb);

char *my_strcpy(char *dest, char const *src);

char *my_strncpy(char *dest, char const *src, int n);

char *my_revstr(char *str);

char *my_strstr(char *str, char const *to_find);

int my_strcmp(char const *s1, char const *s2);

int my_strncmp(char const *s1, char const *s2, int n);

char *my_strupcase(char *str);

char *my_strlowcase(char *str);

char *my_strcapitalize(char *str);

int my_str_isalpha(char const *str);

int my_str_isnum(char const *str);

int my_str_isalphanum(char *str);

int my_str_islower(char const *str);

int my_str_isupper(char const *str);

int my_str_isprintable(char const *str);

int my_showstr(char const *str);

int my_showmem(char const *str, int size);

char *my_strcat(char *dest, char const *src);

char **my_str_to_word_array(char *str, char sep);

char *my_strncat(char *dest, char const *src, int nb);

char *my_malloc_str(char *result, char **argv);

void my_puterror(char *s);

int my_get_env(char **tab, char *s);

#endif
