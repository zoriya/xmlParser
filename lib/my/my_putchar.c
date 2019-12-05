/*
** EPITECH PROJECT, 2019
** Putchar
** File description:
** Yes
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
