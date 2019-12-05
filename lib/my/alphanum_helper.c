/*
** EPITECH PROJECT, 2019
** Helper for the task 4
** File description:
** alphanum_helper
*/

int is_alpha(char c);

int is_digit(char c);

int is_alphanum(char c)
{
    return (is_alpha(c) || is_digit(c));
}

int first_alphanum(const char *str)
{
    for (int i = 0; str[i]; i++) {
        if (is_alphanum(str[i]))
            return i;
    }
    return (-1);
}
