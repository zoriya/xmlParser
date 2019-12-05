/*
** EPITECH PROJECT, 2019
** Str dup replicate
** File description:
** MALLOC YES
*/

#include <stdlib.h>

int my_strlen(const char *src);

char *my_strdup(const char *src)
{
    int length = my_strlen(src);
    char *ret = malloc(sizeof(char) * (length + 1));

    for (int i = 0; i < length; i++)
        ret[i] = src[i];
    ret[length] = '\0';
    return (ret);
}
