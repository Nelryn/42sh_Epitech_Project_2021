/*
** EPITECH PROJECT, 2021
** B-PSU-101-RUN-1-1-minishell1-hugo.baret
** File description:
** my_isalpha
*/

int my_isalpha(char c)
{
    if (c >= 'A' && c <= 'Z')
        return 1;
    else if (c >= 'a' && c <= 'z')
        return 1;
    else
        return 0;
}