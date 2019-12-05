/*
** EPITECH PROJECT, 2019
** String cat
** File description:
** The end of the string.h lib
*/

int my_strlen(const char *dest);

char *my_strcat(char *dest, const char *src)
{
    int i;
    int dest_length = my_strlen(dest);

    for (i = 0; src[i]; i++)
        dest[dest_length + i] = src[i];
    dest[dest_length + i] = '\0';
    return (dest);
}
