/*
** EPITECH PROJECT, 2019
** xmlparser
** File description:
** xml_destroy
*/

#include "xml.h"
#include <stdlib.h>

void xml_free_dict(dictionary *dic)
{
    if (!dic)
        return;
    if (dic->next)
        xml_free_dict(dic->next);
    free(dic->key);
    free(dic->value);
    free(dic);
}

void xml_destroy(node *n)
{
    if (!n)
        return;
    if (n->next)
        xml_destroy(n->next);
    if (n->child)
        xml_destroy(n->child);
    xml_free_dict(n->properties);
    free(n->name);
    free(n);
}