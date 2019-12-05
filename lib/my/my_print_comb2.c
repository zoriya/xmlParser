/*
** EPITECH PROJECT, 2019
** CPool_Day03_2019
** File description:
** Task 6
*/

int my_putchar(char c);

static void print_c2(int i, int j)
{
    my_putchar('0' + i / 10);
    my_putchar('0' + i % 10);
    my_putchar(' ');
    my_putchar('0' + j / 10);
    my_putchar('0' + j % 10);

    if (i != 98) {
        my_putchar(',');
        my_putchar(' ');
    }
}

static void get_group2(int i)
{
    for (int j = i + 1; j <= 99; j++)
        print_c2(i, j);
}

int my_print_comb2(void)
{
    for (int i = 0; i <= 98; i++)
        get_group2(i);

    return (0);
}
