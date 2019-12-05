/*
** EPITECH PROJECT, 2019
** Show Str With non printable values in hexa
** File description:
** Debugger Library
*/

#include <unistd.h>

int is_printable(char c);

int my_putnbr_base(int i, const char *base);

static void puthex(char c)
{
    char zero = '0';
    if (c < 16)
        write(1, &zero, 1);
    my_putnbr_base(c, "0123456789ABCDEF");
}

int my_showstr(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (is_printable(str[i]))
            write(1, &str[i], 1);
        else
            puthex(str[i]);
    }
}
