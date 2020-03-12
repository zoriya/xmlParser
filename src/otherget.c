/*
** EPITECH PROJECT, 2020
** My3D
** File description:
** otherget
*/

#include "xml.h"

char *xml_gettmpstring(node *n, const char *key, char *def)
{
    char *ret = xml_gettempprop(n, key);
    return ret ? ret : def;
}