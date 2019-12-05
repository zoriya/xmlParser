/*
** EPITECH PROJECT, 2019
** CPool_Day03_2019
** File description:
** Task 07
*/

int my_putchar(char c);

static void get_digit(long digit)
{
    long n = digit;
    char c = '0' + n % 10;
    if (n > 9) {
        n /= 10;
        get_digit(n);
    }
    my_putchar(c);
}

int my_put_nbr(int n)
{
    long digit = n;
    if (n < 0) {
        my_putchar('-');
        digit *= -1;
    }
    get_digit(digit);
    return (0);
}
