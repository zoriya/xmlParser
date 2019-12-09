/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** floatutils
*/

#include "my.h"

int get_int_size(int n)
{
    int base_size = my_strlen("0123456789");
    int i = 1;

    while (n >= base_size) {
        n /= base_size;
        i++;
    }
    return (i);
}