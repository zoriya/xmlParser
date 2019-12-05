/*
** EPITECH PROJECT, 2019
** StrStr duplicate
** File description:
** A search in string function
*/

char *my_strstr(char *str, const char *to_find)
{
    int i;
    int search_index = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (to_find[search_index] == '\0')
            return (str + i - search_index);
        if (str[i] == to_find[search_index])
            search_index++;
        else if (str[i] == to_find[0])
            search_index = 1;
        else
            search_index = 0;
    }
    if (to_find[search_index] == '\0')
        return (str + i - search_index);
    return 0;
}
