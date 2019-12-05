/*
** EPITECH PROJECT, 2019
** CPool_Day04_2019
** File description:
** Reverse string
*/

int my_putchar(char c);

char *my_evil_str(char *str)
{
    int count = 0;
    char buf[1598246];

    while (1) {
        buf[count] = str[count];
        if (*(str + count) != '\0')
            count++;
        else
            break;
    }

    for (int i = 0; i < count; i++)
        str[i] = buf[count - i - 1];

    str[count + 1] = '\0';
    return str;
}
