/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** xml
*/

typedef struct node node;
typedef struct dictionary dictionary;

#pragma once

#include <stddef.h>
#include <stdbool.h>

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

node *xml_parse(const char *path);
node *xml_getnode(node *parent, const char *name);
bool xml_hasproperty(node *n, const char *key);
char *xml_getproperty(node *n, const char *key);
char *xml_gettempprop(node *n, const char *key);
int xml_getintprop(node *n, const char *key);
int xml_getbinaprop(node *n, const char *key);
int xml_gethexaprop(node *n, const char *key);
float xml_getfloatprop(node *n, const char *key);
int xml_getchildcount(node *n);
int xml_getchildcount_filtered(node *n, char *name);
void xml_destroy(node *n);