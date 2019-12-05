/*
** EPITECH PROJECT, 2019
** CPool_Day04_2019
** File description:
** Strlen
*/

int my_strlen(const char *str)
{
    if (str == 0)
        return (0);
    for (int i = 0; 1; i++) {
        if (*(str + i) == '\0')
            return i;
    }
}
