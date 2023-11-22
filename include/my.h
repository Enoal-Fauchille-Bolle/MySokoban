/*
** EPITECH PROJECT, 2023
** my
** File description:
** task02
*/

#ifndef MY_H_
    #define MY_H_

void my_putchar(char);
int my_isneg(int);
int my_put_nbr(int);
void my_swap(int *, int *);
int my_putstr(char const *);
int my_strlen(char const *);
int my_getnbr(char const *);
void my_sort_int_array(int *, int);
int my_compute_power_rec(int, int);
int my_compute_square_root(int);
int my_is_prime(int);
int my_find_prime_sup(int);
char *my_strcpy(char *, char const *);
char *my_strncpy(char *, char const *, int);
char *my_revstr(char *);
char *my_strstr(char *, char const *);
int my_strcmp(char const *, char const *);
int my_strncmp(char const *, char const *, int);
char *my_strupcase(char *);
char *my_strlowcase(char *);
char *my_strcapitalize(char *);
int my_str_isalpha(char const *);
int my_str_isnum(char const *);
char *my_strcat(char *, char const *);
char *my_strncat(char *, char const *, int);
char *my_strdup(char const *);
char **my_str_to_word_array(char const *);
int exponent(int, int);
int my_show_word_array(char *const *);
char *my_slice(char const *, int, int);
int my_str_include(char *, char);
char *my_strip(char *, char);
char *my_left_strip(char *, char);
char *my_right_strip(char *, char);
int my_str_get_index(char *str, char c);
void my_sort_str_array(char **array, int size);

#endif /* MY_H_ */
