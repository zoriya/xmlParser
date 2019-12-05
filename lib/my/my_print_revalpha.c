/*
** EPITECH PROJECT, 2019
** CPool_Day03_2019
** File description:
** The second task
*/

int my_putchar(char c);

int my_print_revalpha(void)
{
    for (char i = 'z'; i >= 'a'; i--) {
        my_putchar(i);
    }
    return (0);
}
