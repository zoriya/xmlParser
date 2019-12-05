/*
** EPITECH PROJECT, 2019
** xmlparser
** File description:
** test_main
*/

#include "xml.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc != 2)
        return (printf("Usage: %s xml_path\n", argv[0]), 0);
    node *n = xmlparse(argv[1]);
    (void)n;
    return (0);
}