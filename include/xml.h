/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** xml
*/

#pragma once

typedef struct dictionary
{
    char *property;
    char *value;
} dictionary;

typedef struct node
{
    char *name;
    dictionary *properties;
    node *child;
} node;