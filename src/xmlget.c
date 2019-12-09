/*
** EPITECH PROJECT, 2019
** xmlparser
** File description:
** xmlget
*/

#include "xml.h"
#include "my.h"
#include <stddef.h>

char *xml_getproperty(node *n, const char *key)
{
    for (dictionary *prop = n->properties; prop; prop = prop->next) {
        if (!my_strcmp(key, prop->key))
            return (prop->value);
    }
    return (NULL);
}

int xml_getintprop(node *n, const char *key)
{
    char *prop = xml_getproperty(n, key);

    if (!prop)
        return (0);
    return (my_getnbr(prop));
}

float xml_getfloatprop(node *n, const char *key)
{
    char *prop = xml_getproperty(n, key);

    if (!prop)
        return (0);
    return (0);
}

node *xml_getnode(node *parent, const char *name)
{
    node *tmp;

    if (!my_strcmp(parent->name, name))
        return (parent);
    for (node *n = parent->child; n; n = n->next) {
        if (!my_strcmp(n->name, name))
            return (n);
        tmp = xml_getnode(n, name);
        if (tmp != NULL)
            return (tmp);
    }
    return (NULL);
}