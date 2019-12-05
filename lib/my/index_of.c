/*
** EPITECH PROJECT, 2019
** String helper
** File description:
** Index of char in a string
*/

int index_of(const char *str, const char c)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == c)
            return (i);
    }
    return (-1);
}