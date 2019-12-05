/*
** EPITECH PROJECT, 2019
** Str is alpha
** File description:
** Duplicate of the string.h (I think)
*/

int is_printable(char c)
{
    if (c >= ' ' && c < 127)
        return (1);
    return (0);
}

int my_str_isprintable(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!is_printable(str[i]))
            return (0);
    }
    return (1);
}
