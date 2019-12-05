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

Test(xml, withparam)
{
    char *xml = strdup("<yes params=\"Test\"/>");
    node *n = xml_parsenode(&xml);

    cr_assert_str_eq(n->name, "yes");
    cr_assert_eq(n->child, NULL);
    cr_assert_eq(n->next, NULL);
    cr_assert_str_eq(n->properties->key, "params");
    cr_assert_str_eq(n->properties->value, "Test");
    cr_assert_eq(n->properties->next, NULL);
}

Test(xml, withnext)
{
    char *xml = strdup("<yes params=\"Test\"/><nop/>");
    node *n = xml_parsenode(&xml);

    cr_assert_str_eq(n->name, "yes");
    cr_assert_eq(n->child, NULL);
    cr_assert_str_eq(n->properties->key, "params");
    cr_assert_str_eq(n->properties->value, "Test");
    cr_assert_eq(n->properties->next, NULL);
    cr_assert_str_eq(n->next->name, "nop");
    cr_assert_eq(n->next->child, NULL);
    cr_assert_eq(n->next->properties, NULL);
    cr_assert_eq(n->next->next, NULL);
}