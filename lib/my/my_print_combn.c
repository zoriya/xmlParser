/*
** EPITECH PROJECT, 2019
** CPool_Day03_2019
** File description:
** Task 9
*/

int my_putchar(char c);

static int is_nbr_valid(int n, int i)
{
    if (n < 9) {
        if (n >= i)
            return (0);
        else
            return (1);
    }
    int j = n % 10;

    if (j >= i)
        return (0);
    return is_nbr_valid(n / 10, j);
}

static void print_cn(int n)
{
    if (n > 9)
        print_cn(n / 10);

    my_putchar('0' + n % 10);
}

static void process_valid_number(int n, int starting, int last_valid)
{
    if (last_valid) {
        my_putchar(',');
        my_putchar(' ');
    }
    if (n < starting && starting != 1)
        my_putchar('0');
    print_cn(n);
}

int my_print_combn(int n)
{
    if (n > 10)
        return 0;

    int starting = 1;
    int last_valid = 0;

    for (int i = 0; i < n - 1; i++)
        starting *= 10;

    for (int i = starting / 10; i < starting * 10; i++) {
        if (is_nbr_valid(i, 10)) {
            process_valid_number(i, starting, last_valid);
            last_valid = 1;
        }
    }
    return (0);
}
