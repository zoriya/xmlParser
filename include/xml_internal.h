/*
** EPITECH PROJECT, 2019
** xmlParser
** File description:
** xml_internal
*/

#pragma once

#include <stdbool.h>

void xml_fillclosing_br(char *buffer, const char *name);
char *xml_getname(char **nodestr, bool *has_parameters, bool *has_childs);
dictionary *xml_getproperties(char **nodestr, bool *can_have_child);
char *trimstr(char *str);
int xml_getstringdata(node *n, char **nodestr);
int xml_checkclosing(node *n, char **nodestr);
dictionary *property_add(dictionary *list, dictionary *property);
node *xml_parsenode(char **nodestr);
int get_int_size(int n);