/*
** EPITECH PROJECT, 2019
** Show an array of words on the screen
** File description:
** Nothing to say
*/

void my_putstr(const char *str);

void my_putchar(char c);

int my_show_word_array(const char *words[])
{
    for (int i = 0; words[i]; i++) {
        my_putstr(words[i]);
        my_putchar('\n');
    }
    return (0);
}
