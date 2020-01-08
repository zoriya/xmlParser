/*
** EPITECH PROJECT, 2020
** Twac
** File description:
** strangeget
*/

#include "xml.h"
#include "my.h"

int xml_gethexaprop(node *n, const char *key)
{
    char *prop = xml_getproperty(n, key);

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
    char *prop = xml_getproperty(n, key);

    if (!prop || my_strlen(prop) == 0)
        return (0);
    if (prop[0] == '0' && prop[1] == 'b')
        prop += 2;
    return (my_getnbr_base(prop, "01"));
}