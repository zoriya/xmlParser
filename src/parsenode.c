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

void xml_parsenext(node *n, char **nodestr, int depth)
{
    if (depth != 0)
        n->next = xml_parsenode(nodestr);
    else
        n->next = NULL;
}

int xml_parsechild(node *n, char **nodestr, bool has_child)
{
    char endname[my_strlen(n->name + 3)];
    static int depth = 0;
    char *p;

    if (has_child) {
        xml_fillclosing_br(endname, n->name);
        p = my_strstr(*nodestr, endname);
        if (!p)
            return (-1);
        *p = '\0';
        depth++;
        n->child = xml_parsenode(nodestr);
        if (xml_checkclosing(n, nodestr) < 0)
            return (-1);
        depth--;
    } else
        n->child = NULL;
    xml_parsenext(n, nodestr, depth);
    return (0);
}

node *xml_parseproperties(node *n, char **str, bool has_params, bool has_childs)
{
    if (has_params) {
        n->properties = xml_getproperties(str, &has_childs);
        if (!n->properties)
            return (NULL);
    }
    else
        n->properties = NULL;
    if (xml_parsechild(n, str, has_childs) < 0)
        return (NULL);
    return (n);
}

node *xml_parsenode(char **nodestr)
{
    node *n = malloc(sizeof(node));
    bool has_param;
    bool has_childs;
    char *p = my_strchr(*nodestr, '>');

    if (!n)
        return (NULL);
    if ((*nodestr)[0] == '<') {
        if (p && (*nodestr)[1] != '/') {
            *p = '\0';
            *nodestr += 1;
            n->name = xml_getname(nodestr, &has_param, &has_childs);
            if (n->name)
                return (xml_parseproperties(n, nodestr, has_param, has_childs));
        }
    } else if ((*nodestr)[1] != '/' && xml_getstringdata(n, nodestr) == 0) {
        n->next = xml_parsenode(nodestr);
        return (n);
    }
    free(n);
    return (NULL);
}