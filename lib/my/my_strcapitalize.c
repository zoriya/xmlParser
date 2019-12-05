/*
** EPITECH PROJECT, 2019
** ToUpercase
** File description:
** string.h
*/

int is_num(char c)
{
    return (c >= '0' && c <= '9');
}

int is_letter(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

char *my_strcapitalize(char *str)
{
    int capitalize_next = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (capitalize_next && str[i] > 'a' && str[i] < 'z')
            str[i] += 'A' - 'a';

        if (is_num(str[i]) || is_letter(str[i]))
            capitalize_next = 1;
        else
            capitalize_next = 0;
    }
    return (str);
}
