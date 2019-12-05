/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** xmlparser
*/

#include "xml.h"
#include "xmlstate.h"
#include <stdio.h>

node *xmlparse(char *path)
{
    FILE *file = fopen(path, "r");
    char *line = NULL;
    xmlstate state;

    if (!file)
        return (NULL);
    while ((line = getline(line, 0, file))) {
        xml_parseline(state, line);
    }
    fclose(file);
    return (state.valid);
}