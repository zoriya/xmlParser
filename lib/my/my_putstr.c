/*
** EPITECH PROJECT, 2019
** CPool_Day04_2019
** File description:
** Put string
*/

int my_putchar(char c);

int my_putstr(const char *str)
{
    for (int i = 0; 1; i++) {
        char c = *(str + i);
        if (c == '\0')
            return (0);
        my_putchar(c);
    }
}
