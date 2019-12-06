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
    node *n = xmlparse("tests/testprolog.txt");

    cr_assert_str_eq(n->name, "yes");
    cr_assert_eq(n->next, NULL);
    cr_assert_eq(n->properties, NULL);
    cr_assert_str_eq(n->child->name, "nop");
    cr_assert_eq(n->child->child, NULL);
    cr_assert_eq(n->child->properties, NULL);
    cr_assert_eq(n->child->next, NULL);
}