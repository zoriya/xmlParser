/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** parseline
*/

#include "xml.h"
#include "xml_internal.h"
#include "my.h"
#include <stdlib.h>
#include <stdbool.h>

char *xml_getname(char **nodestr, bool *has_parameters)
{
    char *p = my_strchr(*nodestr, ' ');
    char *name;
    int i = 1;

    *nodestr += 1;
    if (p) {
        *has_parameters = true;
    } else {
        *has_parameters = false;
        p = my_strchr(*nodestr, '/');
        if (!p)
            p = my_strchr(*nodestr, '>');
        else
            i++;
        if (!p)
            return (NULL);
    }
    *p = '\0';
    name = my_strdup(*nodestr);
    *nodestr = p + i;
    return (name);
}

dictionary *xml_getproperty(char **nodestr)
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
        property = xml_getproperty(nodestr);
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

int xml_checkclosing(node *n, char **nodestr)
{
    if (!(*nodestr)[0] && (*nodestr)[1] == '/') {
        if (my_strstr(*nodestr + 1, n->name) != *nodestr + 2)
            return (-1);
        *nodestr += 2 + my_strlen(n->name);
        if ((*nodestr)[0] != '>')
            return (-1);
        *nodestr += 1;
        return (0);
    }
    if (!(*nodestr)[0]) {
        *nodestr += 1;
        return (0);
    }
    return (-1);
}

int xml_parsechild(node *n, char **nodestr, bool has_child)
{
    char endname[my_strlen(n->name + 3)];
    char *p;

    if (has_child) {
        xml_fillclosing_br(endname, n->name);
        p = my_strstr(*nodestr, endname);
        if (!p)
            return (-1);
        *p = '\0';
        n->child = xml_parsenode(nodestr);
        if (!n->child)
            return (-1);
        if (xml_checkclosing(n, nodestr) < 0)
            return (-1);
    } else
        n->child = NULL;
    n->next = xml_parsenode(nodestr);
    return (0);
}

node *xml_parsenode(char **nodestr)
{
    node *n = malloc(sizeof(node));
    bool has_next_value;
    char *p = my_strchr(*nodestr, '>');

    if (!n || !p || (*nodestr)[0] != '<' || (*nodestr)[1] == '/')
        return (NULL);
    *p = '\0';
    n->name = xml_getname(nodestr, &has_next_value);
    if (!n->name)
        return (NULL);
    if (has_next_value) {
        n->properties = xml_getproperties(nodestr, &has_next_value);
        if (!n->properties)
            return (NULL);
    }
    else
        n->properties = NULL;
    if (xml_parsechild(n, nodestr, has_next_value) < 0)
        return (NULL);
    return (n);
}