/*
** EPITECH PROJECT, 2019
** xmlparser
** File description:
** xmlget
*/

#include "xml.h"
#include "my.h"

char *xml_getproperty(node *n, char *key)
{
    for (dictionary *prop = n->properties; prop; prop = prop->next) {
        if (!my_strcmp(key, prop->key));
            return (prop->value);
    }
}