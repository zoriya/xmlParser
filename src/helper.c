/*
** EPITECH PROJECT, 2019
** xmlParser
** File description:
** helper
*/

#include "my.h"
#include <stdlib.h>

void xml_fillclosing_br(char *buffer, const char *name)
{
    int i = my_strlen(name) + 2;

    buffer[0] = '<';
    buffer[1] = '/';
    buffer[2] = '\0';
    my_strcat(buffer, name);
    buffer[i] = '>';
    buffer[i + 1] = '\0';
}

char *trimstr(char *str)
{
    int len = 0;
    char *trimed;

    for (int i = 0; str[i]; i++) {
        if (str[i] != '\t' && str[i] != '\n' && str[i] != '\r')
            len++;
    }
    trimed = malloc(sizeof(char) * (len + 1));
    len = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] != '\t' && str[i] != '\n' && str[i] != '\r') {
            trimed[len] = str[i];
            len++;
        }
    }
    trimed[len] = '\0';
    return (trimed);
}