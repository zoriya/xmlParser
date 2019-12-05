/*
** EPITECH PROJECT, 2019
** Put nbr in a custom base
** File description:
** Might be useful later
*/

#include <unistd.h>

int my_strlen(const char *str);

static void display_a_digit(char c)
{
    write(1, &c, 1);
}

static void put_digit(long n, int base_length, const char *base)
{
    if (n > base_length - 1)
        put_digit(n / base_length, base_length, base);
    display_a_digit(base[n % base_length]);
}

int my_putlong_base(long nbr, const char *base)
{
    int base_length = my_strlen(base);

    if (base_length < 2) {
        display_a_digit('0');
        return (0);
    }
    if (nbr < 0) {
        nbr *= -1;
        display_a_digit('-');
    }
    put_digit(nbr, base_length, base);
    return (0);
}
