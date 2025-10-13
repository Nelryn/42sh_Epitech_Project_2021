/*
** EPITECH PROJECT, 2021
** B-PSU-101-RUN-1-1-minishell1-nicolas.reboule
** File description:
** my_str_isalphanum
*/

#include "my.h"

int my_str_isalphanum(char *str)
{
    int i = 0;

    for (; str[i]; i++) {
        if ((str[i] < 'A' || str[i] > 'Z') && (str[i] < 'a' || str[i] > 'z') &&
        (str[i] < '0' || str[i] > '9')) {
            return (0);
        }
    }
    return (1);
}