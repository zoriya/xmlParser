/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** xmlstate
*/

#pragma once

#include "xml.h"

typedef struct xmlstate
{
    node valid;
    node *current;
} xmlstate;