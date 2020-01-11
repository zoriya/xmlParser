/*
** EPITECH PROJECT, 2019
** xmlparser
** File description:
** xmlget
*/

#include "xml.h"
#include "xml_internal.h"
#include "my.h"
#include "math.h"
#include <stddef.h>

char *xml_gettempprop(node *n, const char *key)
{
    if (!n)
        return (NULL);
    for (dictionary *prop = n->properties; prop; prop = prop->next) {
        if (!my_strcmp(key, prop->key))
            return (prop->value);
    }
    return (NULL);
}

char *xml_getproperty(node *n, const char *key)
{
    char *prop = xml_gettempprop(n, key);

    if (prop)
        return (my_strdup(prop));
    return (NULL);
}

int xml_getintprop(node *n, const char *key)
{
    char *prop = xml_gettempprop(n, key);

    if (!prop || my_strlen(prop) == 0)
        return (0);
    return (my_getnbr(prop));
}

float xml_getfloatprop(node *n, const char *key)
{
    char *prop = xml_gettempprop(n, key);
    float nbr;
    int deci;

    if (!prop)
        return (0);
    for (int i = 0; prop[i]; i++) {
        if (!is_num(prop[i]) && prop[i] != '.')
            return (-1);
    }
    nbr = (float)my_getnbr(prop);
    prop += get_int_size(nbr);
    if (*prop) {
        deci = my_getnbr(prop + 1);
        nbr += deci / pow(10, (float)get_int_size(deci));
    }
    return (nbr);
}

node *xml_getnode(node *parent, const char *name)
{
    node *tmp;

    if (!my_strcmp(parent->name, name))
        return (parent);
    for (node *n = parent->child; n; n = n->next) {
        tmp = xml_getnode(n, name);
        if (tmp != NULL)
            return (tmp);
    }
    return (NULL);
}