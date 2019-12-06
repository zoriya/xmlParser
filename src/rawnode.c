/*
** EPITECH PROJECT, 2019
** xmlparser
** File description:
** rawnode
*/

#include "xml.h"
#include "my.h"
#include <stdlib.h>
#include <stddef.h>

int xml_getstringdata(node *n, char **nodestr)
{
    dictionary *prop = malloc(sizeof(dictionary));
    char *p = my_strchr(*nodestr, '<');

    if (!p)
        return (-1);
    *(p - 1) = '\0';
    prop->key = my_strdup("data");
    prop->value = my_strdup(*nodestr);
    prop->next = NULL;
    *nodestr = p;
    n->name = my_strdup("data");
    n->child = NULL;
    n->properties = prop;
    return (0);
}