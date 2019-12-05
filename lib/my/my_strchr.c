/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** my_strchr
*/

#include "stddef.h"

char *my_strchr(char *str, char c)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == c)
            return (&str[i]);
    }
    return (NULL);
}