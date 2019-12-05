/*
** EPITECH PROJECT, 2019
** ToUpercase
** File description:
** string.h
*/

char *my_strupcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] > 'a' && str[i] < 'z')
            str[i] += 'A' - 'a';
    }
    return (str);
}
