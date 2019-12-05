/*
** EPITECH PROJECT, 2019
** Get number with any base
** File description:
** Int library
*/

int my_strlen(const char *str);

int my_compute_power_it(int i, int p);

static int indexof(char c, const char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            return (i);
    }
    return (-1);
}

static int parse(char *str, const char *base, long n, int i)
{
    int str_length = my_strlen(str);
    int base_length = my_strlen(base);
    int power;
    int neg = 1;

    if (i < 0) {
        neg = -1;
        i *= -1;
    }
    power = my_compute_power_it(base_length, i - 1);
    n += indexof(str[str_length - i], base) * power * neg;
    if ((n > 0 && neg < 0) || (n < 0 && neg > 0))
        return (0);
    if (str_length - i > 0)
        return (parse(str, base, n, (i + 1) * neg));
    return (n);
}

static int get_digit_count(const char *str, const char *base)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (indexof(str[i], base) != -1)
            count++;
        else if (count > 0)
            return (count);
    }
    return (count);
}

int my_getnbr_base(const char *str, const char *base)
{
    int length = get_digit_count(str, base);
    char num[length + 1];
    int start_index = 0;
    int neg = 1;

    if (length == 0)
        return 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (indexof(str[i], base) != -1) {
            num[start_index] = str[i];
            start_index++;
        }
        else if (str[i] == '-')
            neg *= -1;
        else
            break;
    }
    num[length] = '\0';
    return (parse(num, base, 0, neg));
}
