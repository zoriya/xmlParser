/*
** EPITECH PROJECT, 2019
** Convert a string to a char **
** File description:
** Split with every non alpha-numerical characters
*/

#include <stdlib.h>

int is_alphanum(char c);

int first_alphanum(const char *str);

static int count_words(const char *str)
{
    int count = 1;
    int word_length = 0;

    if (first_alphanum(str) == -1)
        return (0);
    for (int i = first_alphanum(str); str[i + 1]; i++) {
        if (!is_alphanum(str[i]) && is_alphanum(str[i + 1]))
            count++;
    }
    return (count);
}

static int get_word_length(const char *str, int n)
{
    int count = 0;
    int word_length = 0;

    for (int i = first_alphanum(str); str[i]; i++) {
        if (!is_alphanum(str[i]) && is_alphanum(str[i + 1]))
            count++;
        else if (count == n && is_alphanum(str[i]))
            word_length++;
    }
    return (word_length);
}

static char *get_word(const char *str, int n)
{
    int length = get_word_length(str, n);
    char *ret = malloc(sizeof(*ret) * (length + 1));
    int count = 0;
    int word_length = 0;

    for (int i = first_alphanum(str); word_length != length; i++) {
        if (!is_alphanum(str[i]) && is_alphanum(str[i + 1]))
            count++;
        else if (count == n) {
            ret[word_length] = str[i];
            word_length++;
        }
    }
    ret[length] = '\0';
    return (ret);
}

char **my_str_to_word_array(const char *str)
{
    int count = count_words(str);
    char **ret = malloc(sizeof(*ret) * (count + 1));

    for (int i = 0; i < count; i++) {
        ret[i] = get_word(str, i);
    }
    ret[count] = 0;
    return (ret);
}
