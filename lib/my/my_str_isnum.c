/*
** EPITECH PROJECT, 2019
** Str is alpha
** File description:
** Duplicate of the string.h (I think)
*/

int is_digit(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

int my_str_isnum(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!is_digit(str[i]))
            return (0);
    }
    return (1);
}
