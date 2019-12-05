/*
** EPITECH PROJECT, 2019
** CPool_Day05_2019
** File description:
** Factorials
*/

int my_compute_factorial_it(int nb)
{
    if (nb < 0)
        return 0;

    int ret = 1;
    while (nb > 0) {
        ret *= nb;
        nb--;

        if (ret < 0)
            return 0;
    }
    return ret;
}
