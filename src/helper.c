/*
** EPITECH PROJECT, 2019
** xmlParser
** File description:
** helper
*/

#include "my.h"

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