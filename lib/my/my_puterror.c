/*
** EPITECH PROJECT, 2021
** B-PSU-210-RUN-2-1-bsminishell2-emilie.baunifais
** File description:
** puterror
*/

#include <unistd.h>

int my_strlen(char *);

void my_puterror(char *s)
{
    write(2, s, my_strlen(s));
}