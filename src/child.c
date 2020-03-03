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
    while (n) {
        if (!my_strcmp(n->name, name))
            i++;
        n = n->next;
    }
    return (i);
}

int xml_getchildcount(node *n)
{
    int i = 1;

    if (!n || !n->child)
        return (0);
    n = n->child;
    while (n) {
        i++;
        n = n->next;
    }
    return (i);
}