/*
** EPITECH PROJECT, 2019
** CPool_Day05_2019
** File description:
** Power calculator
*/

int my_compute_power_it(int nb, int p)
{
    int ret = 1;
    int mult = 1;

    if (p < 0)
        return 0;
    if (nb < 0) {
        nb *= -1;
        if (p % 2 == 1)
            mult = -1;
    }
    while (p > 0) {
        ret *= nb;
        p--;

        if (ret < 0)
            return (0);
    }

    return (ret * mult);
}
