/*
** EPITECH PROJECT, 2019
** String copy n first chars
** File description:
** Same but different
*/

char *my_strncpy(char *dest, const char* src, int n)
{
    int overflow = 0;

    for (int i = 0; i < n; i++) {
        if (overflow)
            dest[i] = '\0';
        else {
            dest[i] = src[i];
            overflow = (src[i] == '\0');
        }
    }
    return (dest);
}
