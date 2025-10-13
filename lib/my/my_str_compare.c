/*
** EPITECH PROJECT, 2021
** B-CPE-110-RUN-1-1-antman-hugo.baret
** File description:
** my_str_compare
*/

#include "my.h"

int str_compare(char *str1, char *str2)
{
    int i = 0;

    if (my_strlen(str1) != my_strlen(str2))
        return 0;
    for (; str1[i] != '\0'; i++) {
        if (str1[i] != str2[i])
            return 0;
    }
    return 1;
}