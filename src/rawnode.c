/*
** EPITECH PROJECT, 2019
** xmlparser
** File description:
** rawnode
*/

#include "xml.h"
#include "xml_internal.h"
#include "my.h"
#include <stdlib.h>
#include <stddef.h>

int xml_getstringdata(node *n, char **nodestr)
{
    dictionary *prop = malloc(sizeof(dictionary));

    prop->key = my_strdup("data");
    prop->value = my_strdup(*nodestr);
    prop->next = NULL;
    *nodestr += my_strlen(*nodestr);
    n->name = my_strdup("data");
    n->child = NULL;
    n->properties = prop;
    return (0);
}