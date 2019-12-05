/*
** EPITECH PROJECT, 2019
** CPool_Day05_2019
** File description:
** Check if a number is a prime number
*/

int my_compute_square_root(int n);

int my_is_prime(int n)
{
    int square;

    if (n <= 1)
        return (0);
    if (n == 2)
        return (1);
    for (int i = 0; i * i <= n; i++)
        square = i;
    for (int i = 2; i < square + 1; i++) {
        if (n % i == 0)
            return 0;
    }

    return (1);
}
