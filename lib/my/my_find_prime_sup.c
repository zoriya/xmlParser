/*
** EPITECH PROJECT, 2019
** CPool_Day05_2019
** File description:
** Find a prime number greater than the given number
*/

int my_is_prime(int n);

int my_find_prime_sup(int n)
{
    if (n <= 2)
        return (2);
    while (!my_is_prime(n))
        n++;

    return n;
}
