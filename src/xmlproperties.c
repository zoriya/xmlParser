/*
** EPITECH PROJECT, 2019
** xmlparser
** File description:
** xmlproperties
*/

#include "my.h"
#include "xml.h"
#include "xml_internal.h"
#include <stdlib.h>
#include <stdbool.h>

char *xml_getname(char **nodestr, bool *has_parameters, bool *has_childs)
{
    char *p = my_strchr(*nodestr, ' ');
    char *name;
    int i = 1;

    if (p)
        *has_parameters = true;
    else {
        *has_parameters = false;
        if (!(p = my_strchr(*nodestr, '/'))) {
            p = my_strchr(*nodestr, '>');
            *has_childs = true;
        } else {
            i++;
            *has_childs = false;
        } if (!p)
            p = *nodestr + my_strlen(*nodestr);
    }
    *p = '\0';
    name = my_strdup(*nodestr);
    *nodestr = p + i;
    return (name);
}

dictionary *xml_parseproperty(char **nodestr)
{
    dictionary *property = malloc(sizeof(dictionary));
    char *p;

    if (!property)
        return (NULL);
    p = my_strchr(*nodestr, '=');
    if (!p)
        return (NULL);
    *p = '\0';
    property->key = my_strdup(*nodestr);
    *nodestr = p + 1;
    if ((*nodestr)[0] != '"')
        return (NULL);
    *nodestr += 1;
    p = my_strchr(*nodestr, '"');
    if (!p)
        return (NULL);
    *p = '\0';
    property->value = my_strdup(*nodestr);
    *nodestr = p + 1;
    return (property);
}

dictionary *xml_getproperties(char **nodestr, bool *can_have_child)
{
    dictionary *properties = NULL;
    dictionary *property = NULL;

    while ((*nodestr)[0] != '\0') {
        property = xml_parseproperty(nodestr);
        if (!property)
            return (NULL);
        properties = property_add(properties, property);
        if ((*nodestr)[0] == ' ')
            *nodestr += 1;
        if ((*nodestr)[0] == '/') {
            *nodestr += 1;
            *can_have_child = false;
        }
        else
            *can_have_child = true;
    }
    *nodestr += 1;
    return (properties);
}