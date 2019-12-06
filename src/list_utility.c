/*
** EPITECH PROJECT, 2019
** xmlparser
** File description:
** list_utility
*/

#include "xml.h"
#include <stddef.h>

dictionary *property_add(dictionary *list, dictionary *property)
{
    dictionary *listconst = list;

    property->next = NULL;
    if (!list)
        return (property);
    else {
        while (list->next)
            list = list->next;
        list->next = property;
    }
    return (listconst);
}