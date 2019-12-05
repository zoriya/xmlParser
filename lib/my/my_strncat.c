/*
** EPITECH PROJECT, 2019
** String N Cat
** File description:
** End of the string.h lib
*/

int my_strlen(const char *str);

char *my_strncat(char *dest, const char *src, int n)
{
    int i;
    int dest_length = my_strlen(dest);

    for (i = 0; i < n && src[i]; i++)
        dest[dest_length + i] = src[i];
    dest[dest_length + i] = '\0';
    return (dest);
}
