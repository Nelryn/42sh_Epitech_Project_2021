/*
** EPITECH PROJECT, 2020
** my_strncpy
** File description:
** my_strncpy
*/

int my_strlen(char const *str);

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    if (n < my_strlen(src)) {
        while (src[i] != src[n]) {
            dest[i] = src[i];
            i = i + 1;
        }
    } else if (n > my_strlen(src)) {
        while (src[i] != src[n]) {
            dest[i] = src[i];
            i = i + 1;
        }
        dest[i] = '\0';
    }
    return (dest);
}
