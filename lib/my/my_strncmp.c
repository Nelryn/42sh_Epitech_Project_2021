/*
** EPITECH PROJECT, 2020
** my_strncmp
** File description:
** my_strncmp
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int x = 0;

    for (; x != n; x++) {
        if (s1[x] != s2[x])
            return 0;
    }
    return (1);
}
