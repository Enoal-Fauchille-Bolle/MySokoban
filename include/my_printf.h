/*
** EPITECH PROJECT, 2023
** my_printf Constants
** File description:
** Constants declaration
*/

#ifndef MY_PRINTF_H_
    #define MY_PRINTF_H_

    #include "my.h"
    #include <stdarg.h>

int my_put_nbr2(va_list list, char *modifiers);
int my_put_nbr_u(va_list list, char *modifiers);
int my_str_char_counter(char c, char *str);

char *convert_base(char const *nbr, char const
    *base_from, char const *base_to);
int my_printf(const char *restrict format, ...);
void specifier_s(va_list list, int *counter, char *modifiers);
void specifier_e(va_list list, int *counter, char *modifiers);
void specifier_e_maj(va_list list, int *counter, char *modifiers);
void specifier_c(va_list list, int *counter, char *modifiers);
void specifier_i_and_d(va_list list, int *counter, char *modifiers);
void specifier_percent(va_list list, int *counter, char *modifiers);
void specifier_x(va_list list, int *counter, char *modifiers);
void specifier_x_maj(va_list list, int *counter, char *modifiers);
void specifier_o(va_list list, int *counter, char *modifiers);
void specifier_b(va_list list, int *counter, char *modifiers);
void specifier_b_maj(va_list list, int *counter, char *modifiers);
void specifier_p(va_list list, int *counter, char *modifiers);
void specifier_n(va_list list, int *counter, char *modifiers);
void specifier_f(va_list list, int *counter, char *modifiers);
void specifier_f_maj(va_list list, int *counter, char *modifiers);
void specifier_u(va_list list, int *counter, char *modifiers);
// void specifier_g(va_list list, int *counter, char *modifiers);
char *separate_modifiers_from_str(char *str);
int in_modifiers(int pos, char to_search, char *modifiers);
int number_in_modifiers(int pos, char *modifiers);
int my_getnbr_modifiers(char *modifiers);
int absolue(int nb);
void calcul_nb_character(int nb, int *nb_character_nb);
int get_nbrlen(int nb);
int print_spaces(int nb_spaces);
int print_zeros(int nb_zeros);
char *my_slice(char const *, int, int);
char *my_strcpy(char *dest, char const *src);
int my_compute_power_rec(int nb, int p);
char *my_revstr(char *str);
int exponent(int x, int y);
int my_strlen(char const *str);
int my_str_get_index(char *str, char c);
int my_str_include(char *str, char c);

    #define MODIFIERS "+- #0"
    #define LENGTH_MODIFIERS "hlqLjzZt"
    #define SPECIFIER_CALLS "scid%xoXbBpnfFuFeE"
extern void (*SPECIFIER_FUNCTIONS[]) (va_list, int *, char *);

#endif /* MY_PRINTF_H_ */
