/*
** EPITECH PROJECT, 2020
** Twac
** File description:
** child
*/

#include "xml.h"
#include "my.h"

int xml_getchildcount_filtered(node *n, char *name)
{
    int i = 0;

    if (!n || !n->child)
        return (0);
    n = n->child;
    while (n->next) {
        n = n->next;
        if (!my_strcmp(n->name, name))
            i++;
    }
    return (i);
}

int xml_getchildcount(node *n)
{
    int i = 1;

    if (!n || !n->child)
        return (0);
    n = n->child;
    while (n->next) {
        n = n->next;
        i++;
    }
    return (i);
}