/*
** EPITECH PROJECT, 2021
** project
** File description:
** my_arrlen
*/

int my_arrlen(char **arr)
{
    int i = 0;

    for (; arr[i]; i++);
    return (i);
}