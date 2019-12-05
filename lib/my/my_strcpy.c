/*
** EPITECH PROJECT, 2019
** String copy
** File description:
** Copy an entire string
*/

char *my_strcpy(char *dest, const char *src)
{
    int i;

    for (i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}
