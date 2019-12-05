/*
** EPITECH PROJECT, 2019
** xmlparser
** File description:
** test_basics
*/

#include "xml.h"
#include <criterion/criterion.h>
#include <string.h>

Test(xml, simple)
{
    char *xml = strdup("<yes/>");
    node *n = xml_parsenode(&xml);

    cr_assert_str_eq(n->name, "yes");
    cr_assert_eq(n->child, NULL);
    cr_assert_eq(n->next, NULL);
    cr_assert_eq(n->properties, NULL);
}