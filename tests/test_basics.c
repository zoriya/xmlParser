/*
** EPITECH PROJECT, 2019
** xmlparser
** File description:
** test_basics
*/

#include "xml.h"
#include "xml_internal.h"
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
    char *xml = strdup("<yes params=\"Test\"><nop/><yep/></yes>");
    node *n = xml_parsenode(&xml);

    cr_assert_str_eq(n->name, "yes");
    cr_assert_str_eq(n->child->name, "nop");
    cr_assert_eq(n->child->child, NULL);
    cr_assert_eq(n->child->properties, NULL);
    cr_assert_str_eq(n->child->next->name, "yep");
    cr_assert_eq(n->child->next->child, NULL);
    cr_assert_eq(n->child->next->properties, NULL);
    cr_assert_eq(n->child->next->next, NULL);
    cr_assert_str_eq(n->properties->key, "params");
    cr_assert_str_eq(n->properties->value, "Test");
    cr_assert_eq(n->properties->next, NULL);
}

Test(xml, withchild)
{
    char *xml = strdup("<yes><nop/></yes>");
    node *n = xml_parsenode(&xml);

    cr_assert_str_eq(n->name, "yes");
    cr_expect_eq(n->next, NULL);
    cr_assert_eq(n->properties, NULL);
    cr_assert_str_eq(n->child->name, "nop");
    cr_assert_eq(n->child->child, NULL);
    cr_assert_eq(n->child->properties, NULL);
    cr_assert_eq(n->child->next, NULL);
}

Test(xml, withchildwparams)
{
    char *xml = strdup("<yes params=\"Test\"><nop/></yes>");
    node *n = xml_parsenode(&xml);

    cr_assert_str_eq(n->name, "yes");
    cr_assert_eq(n->next, NULL);
    cr_assert_str_eq(n->properties->key, "params");
    cr_assert_str_eq(n->properties->value, "Test");
    cr_assert_eq(n->properties->next, NULL);
    cr_assert_str_eq(n->child->name, "nop");
    cr_assert_eq(n->child->child, NULL);
    cr_assert_eq(n->child->properties, NULL);
    cr_assert_eq(n->child->next, NULL);
}