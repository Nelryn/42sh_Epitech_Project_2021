/*
** EPITECH PROJECT, 2021
** B-CPE-200-RUN-2-1-matchstick-hugo.baret
** File description:
** free_arr
*/

#include "my.h"

void free_array(char **arr)
{
    if (arr == NULL)
        return;
    for (int i = 0; arr[i]; i++) {
        free(arr[i]);
        arr[i] = NULL;
    }
    free(arr);
    arr = NULL;
}