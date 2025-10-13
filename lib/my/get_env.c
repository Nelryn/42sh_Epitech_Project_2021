/*
** EPITECH PROJECT, 2021
** B-PSU-101-RUN-1-1-minishell1-emilie.baunifais
** File description:
** get_env
*/

#include <stddef.h>

int my_strlen(char *);
int my_strncmp(char *ref, char *cmp, int n);

int my_get_env(char **tab, char *s)
{
    int i = 0;

    while (tab[i] != NULL) {
        if (my_strncmp(tab[i], s, my_strlen(s)) == 0)
            return 1;
        i++;
    }
    return 0;
}