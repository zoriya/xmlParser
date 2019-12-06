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