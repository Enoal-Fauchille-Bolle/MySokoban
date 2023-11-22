/*
** EPITECH PROJECT, 2023
** my_put_nbr
** File description:
** display the number in parameter
*/
#include "my.h"
#include "my_printf.h"
#include <stdarg.h>

static int divide_and_remove(unsigned int nb, long long divisible, int *debut)
{
    int value;

    value = nb / divisible;
    if (value < 0) {
        value = -value;
    }
    if ((value != 0 && *debut == 8) || divisible == 1) {
        *debut = divisible;
    }
    if (*debut != 8) {
        my_putchar(value + '0');
    }
    return value;
}

static int print_nbr(unsigned int nb)
{
    int debut = 8;
    int	len = 1;
    long long j = 1;

    while (nb / my_compute_power_rec(10, len - 1) >= 10) {
        len++;
    }
    for (int i = len; i > 0; i--) {
        j *= 10;
    }
    for (long long i = j; i >= 1; i = i / 10) {
        nb = nb - (divide_and_remove(nb, i, &debut) * i);
    }
    return len;
}

static unsigned int initialisation(int *nb_min_char, int *nb_precision,
    char *modifiers, va_list list)
{
    int start_min = number_in_modifiers(1, modifiers);
    int	start_prec = number_in_modifiers(2, modifiers);

    if (in_modifiers(1, '*', modifiers) == 1) {
        *nb_min_char = va_arg(list, int);
    } else if (number_in_modifiers(1, modifiers) != -1) {
        *nb_min_char = my_getnbr_modifiers(modifiers + start_min);
    }
    if (in_modifiers(2, '*', modifiers) == 1) {
        *nb_precision = va_arg(list, int);
    } else if (number_in_modifiers(2, modifiers) != -1) {
        *nb_precision = my_getnbr_modifiers(modifiers + start_prec);
    }
    return va_arg(list, unsigned int);
}

static void test_replace_zero(char *modifiers, int *nb_zeros, int *nb_spaces)
{
    if (in_modifiers(0, '0', modifiers) == 1 &&
        in_modifiers(0, '-', modifiers) != 1 &&
        (in_modifiers(0, '*', modifiers) != 1) &&
        number_in_modifiers(2, modifiers) == -1) {
        *nb_zeros = *nb_spaces;
        *nb_spaces = 0;
    }
}

static void set_numbers(int *nb_character_nb,
    unsigned int nb, int *nb_zeros, int *nb_spaces)
{
    calcul_nb_character(nb, nb_character_nb);
    *nb_zeros -= *nb_character_nb;
    if (*nb_zeros < 0) {
        *nb_zeros = 0;
    }
    *nb_spaces -= *nb_character_nb + *nb_zeros;
}

static int print_all(unsigned int nb, char *modifiers,
    int nb_min_char, int nb_precision)
{
    int nb_spaces = nb_min_char;
    int nb_zeros = nb_precision;
    int nb_character_nb = 0;
    int length = 0;

    set_numbers(&nb_character_nb, nb, &nb_zeros, &nb_spaces);
    test_replace_zero(modifiers, &nb_zeros, &nb_spaces);
    if (in_modifiers(0, '-', modifiers) == 0) {
        length += print_spaces(nb_spaces);
    }
    length += print_zeros(nb_zeros) + print_nbr(nb);
    if (in_modifiers(0, '-', modifiers) == 1) {
        length += print_spaces(nb_spaces);
    }
    return length;
}

int my_put_nbr_u(va_list list, char *modifiers)
{
    unsigned int nb = 0;
    int nb_min_char = -1;
    int nb_precision = -1;
    int length = 0;

    nb = initialisation(&nb_min_char, &nb_precision, modifiers, list);
    length += print_all(nb, modifiers, nb_min_char, nb_precision);
    return length;
}
