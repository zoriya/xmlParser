/*
** EPITECH PROJECT, 2019
** Str is alpha
** File description:
** Duplicate of the string.h (I think)
*/

int is_upper(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (1);
    return (0);
}

int my_str_isupper(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!is_upper(str[i]))
            return (0);
    }
    return (1);
}
