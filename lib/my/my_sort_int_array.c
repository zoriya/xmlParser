/*
** EPITECH PROJECT, 2019
** CPool_Day04_2019
** File description:
** Int array sorter
*/

static int sort_linear(int *array, int size)
{
    for (int i = 0; i < size - 1; i++) {
        if (array[i] > array[i + 1]) {
            int buf = array[i];
            array[i] = array[i + 1];
            array[i + 1] = buf;
        }
    }
}

int my_sort_int_array(int *array, int size)
{
    for (int i = 0; i < size; i++)
        sort_linear(array, size);
}
