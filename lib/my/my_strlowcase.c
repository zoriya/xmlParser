/*
** EPITECH PROJECT, 2019
** ToUpercase
** File description:
** string.h
*/

char *my_strlowcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] > 'A' && str[i] < 'Z')
            str[i] += 'a' - 'A';
    }
    return (str);
}
