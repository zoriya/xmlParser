/*
** EPITECH PROJECT, 2019
** CPool_Day04_2019
** File description:
** Reverse string
*/

int my_strlen(char *str);

char *my_revstr(char *str)
{
    int length = my_strlen(str);
    char dup[length + 1];

    for (int i = 0; i < length; i++)
        dup[i] = str[i];
    for (int i = 0; i < length; i++)
        str[i] = dup[length - 1 - i];
    str[length] = '\0';
    return (str);
}
