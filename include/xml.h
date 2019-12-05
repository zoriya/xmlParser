/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** xml
*/

typedef struct node node;
typedef struct dictionary dictionary;

#pragma once

struct dictionary
{
    char *key;
    char *value;

    dictionary *next;
};

struct node
{
    char *name;
    dictionary *properties;
    node *child;

    node *next;
};

dictionary *property_add(dictionary *list, dictionary *property);
node *xml_parsenode(char **nodestr);