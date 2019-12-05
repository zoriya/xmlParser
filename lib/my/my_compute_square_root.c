/*
** EPITECH PROJECT, 2019
** CPool_Day05_2019
** File description:
** Square root calculator
*/

int my_compute_square_root(int nb)
{
    if (nb < 0)
        return 0;

    for (int i = 0; 1; i++) {
        int power = i * i;
        if (power == nb)
            return i;
        else if (power > nb)
            return 0;
    }

    return 0;
}
