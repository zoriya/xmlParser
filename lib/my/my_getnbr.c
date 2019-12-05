/*
** EPITECH PROJECT, 2019
** CPool_Day04_2019
** File description:
** Int parser
*/

int my_putchar(char c);

static int parse(const char *str, int digit_count, int neg)
{
    int n = 0;
    int add;
    for (int power = 0; power < digit_count; power++) {
        add = str[digit_count - power - 1] - '0';
        if (power == 10 && add > 2)
            return 0;

        add *= neg;
        for (int i = 0; i < power; i++) {
            add *= 10;
            if (add * neg < 0)
                return 0;
        }
        n += add;

        if ((neg == -1 && n > 0) || neg == 1 && n < 0)
            return 0;
    }
    return n;
}

static int init_print(const char *str, int count, int s_index)
{
    int neg = 1;

    for (char c = str[s_index]; c == '-' || c == '+'; c = str[s_index]) {
        if (c == '-')
            neg *= -1;
        s_index++;
        count--;
    }

    char buf[count];
    for (int i = 0; i < count; i++)
        buf[i] = str[s_index + i];


    return parse(buf, count, neg);
}

int my_getnbr(const char *str)
{
    int count = 0;
    int start_index = -1;
    char c;

    for (int i = 0; 1; i++) {
        c = str[i];
        if (c >= '0' && c <= '9' || c == '-' || c == '+') {
            if (start_index == -1)
                start_index = i;
            count++;
        }
        else if (count > 0 || c == '\0')
            break;
    }
    return init_print(str, count, start_index);
}
