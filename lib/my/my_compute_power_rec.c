/*
** EPITECH PROJECT, 2019
** CPool_Day05_2019
** File description:
** Power calculator but in recursive mode
*/

static int calculate(int nb, int p, int ret)
{
    if (ret < 0)
        return 0;

    if (p == 0)
        return ret;

    return calculate(nb, p - 1, ret * nb);
}

int my_compute_power_rec(int nb, int p)
{
    int mult = 1;

    if (p < 0)
        return (0);
    if (nb < 0) {
        nb *= -1;
        if (p % 2 == 1)
            mult = -1;
    }
    return (calculate(nb, p, 1) * mult);
}
