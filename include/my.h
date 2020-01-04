/*
** EPITECH PROJECT, 2019
** My lib
** File description:
** Header file
*/
#pragma once

int my_str_islower_or_num(const char *str);

int count_valid_queens_placements(int n);

char *my_strchr(char *str, char c);

int my_compute_power_it(int n, int p);

int my_compute_power_rec(int n, int p);

int my_compute_factorial_it(int n);

int my_compute_factorial_rec(int n);

int my_compute_square_root(int n);

char *my_evil_str(char *str);

int my_find_prime_sup(int n);

int my_getnbr_base(const char *str, const char *base);

int my_getnbr(const char *str);

int my_isneg(int n);

int my_is_prime(int n);

void my_print_alpha(void);

void my_print_comb2(void);

void my_print_combn(int n);

void my_print_comb(void);

void my_print_digits(void);

void my_print_revalpha(void);

void my_putchar(char c);

void my_putlong_base(long n, const char *base);

void my_putnbr_base(int n, const char *base);

void my_put_nbr(int n);

void my_putstr(const char *str);

void my_revstr(char *str);

void my_showmem(const char *str);

void my_showstr(const char *str);

void my_sort_int_array(int *array);

int is_letter(char c);

int is_alpha(char c);

int is_num(char c);

int is_digit(char c);

char *my_strcapitalize(char *str);

char *my_strcat(char *dest, const char *src);

int my_strcmp(const char *s1, const char *s2);

char *my_strcpy(const char *str);

int my_str_isalpha(const char *str);

int is_lowercase(char c);

int my_str_islower(const char *str);

int my_str_isnum(const char *str);

int is_printable(char c);
int my_str_isprintable(const char *str);

int is_upper(char c);
int my_str_isupper(const char *str);

int my_strlen(const char *str);

int my_strlowcase(const char *str);

char *my_strncat(char *dest, const char *src, int n);

int my_strncmp(const char *s1, const char *s2, int n);

char *my_strncpy(char *dest, const char *src, int n);

char *my_strstr(const char *str, const char *to_find);

int my_strupcase(const char *str);

void my_swap(int *a, int *b);

char *my_strdup(const char *str);

char **my_str_to_word_array(const char *str);

int my_show_word_array(const char **words);

int is_alphanum(char c);

int first_alphanum(const char *str);

int index_of(const char *str, char c);