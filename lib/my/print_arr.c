/*
** EPITECH PROJECT, 2021
** B-CPE-200-RUN-2-1-matchstick-hugo.baret
** File description:
** print_arr
*/

#include "my.h"

void print_arr(char **arr)
{
    for (int i = 0; arr[i]; i++)
        my_printf("%s\n", arr[i]);
}