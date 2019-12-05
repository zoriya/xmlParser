/*
** EPITECH PROJECT, 2019
** StrNCmp
** File description:
** String.h duplicate
*/

int my_strncmp(const char *str1, const char *str2, int n)
{
    int i;
    int ret;

    for (i = 0; i < n && str1[i] != '\0'; i++) {
        if (str2[i] == '\0')
            return str1[i];
        ret = str1[i] - str2[i];
        if (ret != 0)
            return (ret);
    }

    if (i == n || str2[i] == '\0')
        return (0);
    else
        return -str2[i];
}
