/*
** EPITECH PROJECT, 2020
** Twac
** File description:
** strangeget
*/

#include "xml.h"
#include "xml_internal.h"
#include "my.h"
#include <stddef.h>

int xml_gethexaprop(node *n, const char *key)
{
    char *prop = xml_gettempprop(n, key);

    if (!prop || my_strlen(prop) == 0)
        return (0);
    if (prop[0] == '0' && prop[1] == 'x')
        prop += 2;
    if (my_str_islower_or_num(prop))
        return (my_getnbr_base(prop, "0123456789abcdef"));
    else
        return (my_getnbr_base(prop, "0123456789ABCDEF"));
}

int xml_getbinaprop(node *n, const char *key)
{
    char *prop = xml_gettempprop(n, key);

    if (!prop || my_strlen(prop) == 0)
        return (0);
    if (prop[0] == '0' && prop[1] == 'b')
        prop += 2;
    return (my_getnbr_base(prop, "01"));
}

bool xml_hasproperty(node *n, const char *key)
{
    return (xml_gettempprop(n, key) != NULL);
}

bool xml_propcontains(node *n, const char *key, const char *tofind)
{
    char *tmp = xml_gettempprop(n, key);

    return tmp && my_strstr(tmp, tofind);
}

bool xml_getbool(node *n, const char *key, bool default_value)
{
    char *tmp = xml_gettempprop(n, key);

    if (tmp && !my_strcmp(tmp, "true"))
        return (true);
    if (tmp && !my_strcmp(tmp, "True"))
        return (true);
    if (tmp && !my_strcmp(tmp, "false"))
        return (false);
    if (tmp && !my_strcmp(tmp, "False"))
        return (false);
    return (default_value);
}