/*
** EPITECH PROJECT, 2019
** xmlparser
** File description:
** test_main
*/

#include "xml.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc != 2)
        return (printf("Usage: %s xml_path\n", argv[0]), 0);
    node *n = xml_parse(argv[1]);
    xml_destroy(n);
    return (0);
}