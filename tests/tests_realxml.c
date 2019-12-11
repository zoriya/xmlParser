/*
** EPITECH PROJECT, 2019
** xmlparser
** File description:
** tests_realxml
*/

#include "xml.h"
#include <criterion/criterion.h>
#include <string.h>

Test(xml, complete)
{
    node *n = xml_parse("tests/testprolog.txt");

    cr_assert_str_eq(n->name, "yes");
    cr_assert_eq(n->next, NULL);
    cr_assert_eq(n->properties, NULL);
    cr_assert_str_eq(n->child->name, "nop");
    cr_assert_eq(n->child->child, NULL);
    cr_assert_eq(n->child->properties, NULL);
    cr_assert_str_eq(n->child->next->name, "Test");
    cr_assert_eq(n->child->next->properties, NULL);
    cr_assert_eq(n->child->next->child, NULL);
    cr_assert_eq(n->child->next->next, NULL);
}

Test(xml, completewstring)
{
    node *n = xml_parse("tests/teststring.txt");

    cr_assert_str_eq(n->name, "entity");
    cr_assert_eq(n->next, NULL);
    cr_assert_str_eq(n->properties->key, "id");
    cr_assert_str_eq(n->properties->value, "0");
    cr_assert_eq(n->properties->next, NULL);
    cr_assert_str_eq(n->child->name, "PositionComponent");
    cr_assert_eq(n->child->properties, NULL);
    cr_assert_eq(n->child->next, NULL);
    cr_assert_str_eq(n->child->child->name, "pos");
    cr_assert_str_eq(n->child->child->child->properties->value, "5,5");
    cr_assert_str_eq(n->child->child->next->name, "size");
    cr_assert_str_eq(n->child->child->next->properties->key, "x");
    cr_assert_str_eq(n->child->child->next->properties->value, "500");
    cr_assert_str_eq(n->child->child->next->properties->next->key, "y");
    cr_assert_str_eq(n->child->child->next->properties->next->value, "500");
}