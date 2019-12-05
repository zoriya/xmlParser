/*
** EPITECH PROJECT, 2019
** CPool_Day03_2019
** File description:
** Task 5
*/

int my_putchar(char c);

static void print_c(char x, char y, char z)
{
    my_putchar(x);
    my_putchar(y);
    my_putchar(z);
}

static void increment_y(char *x, char *y, char *z)
{
    *x = *x + 1;
    *y = *x + 1;
    *z = *y + 1;
}

int my_print_comb(void)
{
    char x = '0';
    char y = '1';
    char z = '2';

    while (1) {
        print_c(x, y, z);
        z++;
        if (z > '9') {
            y++;
            z = y + 1;
        }
        if (y > '8')
            increment_y(&x, &y, &z);
        if (x <= '7') {
            my_putchar(',');
            my_putchar(' ');
        }
        else
            return 0;
    }
}
