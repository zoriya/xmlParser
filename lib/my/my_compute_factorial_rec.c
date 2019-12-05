/*
** EPITECH PROJECT, 2019
** CPool_Day05_2019
** File description:
** Factorials but in recursive mode
*/

int compute(int nb, int ret)
{
    if (ret < 0)
        return (0);

    if (nb == 0)
        return (ret);

    return (compute(nb - 1, ret * nb));
}

int my_compute_factorial_rec(int nb)
{
    if (nb == 0)
        return (1);

    return (compute(nb, 1));
}
