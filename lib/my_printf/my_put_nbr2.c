/*
** EPITECH PROJECT, 2023
** my_put_nbr
** File description:
** display the number in parameter
*/

#include "my.h"
#include "my_printf.h"
#include <stdarg.h>

static int my_isneg_print(int n, char *modifiers)
{
    if (n < 0) {
        my_putchar('-');
        return 1;
    }
    if (in_modifiers(0, '+', modifiers) == 1){
        my_putchar('+');
        return 1;
    }
    if (in_modifiers(0, ' ', modifiers) == 1){
        my_putchar(' ');
        return 1;
    }
    return 0;
}

static int divide_and_remove(int nb, int divisible, int *debut)
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

static int print_nbr(int nb)
{
    int debut = 8;
    int	len = 1;

    while ((absolue(nb) / my_compute_power_rec(10, len - 1)) >= 10) {
        len++;
    }
    for (int i = my_compute_power_rec(10, len); i >= 1; i = i / 10) {
        if (nb < 0) {
            nb = nb + (divide_and_remove(nb, i, &debut)*i);
        } else {
            nb = nb - (divide_and_remove(nb, i, &debut)*i);
        }
    }
    return len;
}

static int initialisation(int *nb_min_char, int *nb_precision,
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
    return va_arg(list, int);
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
    int nb, int *nb_zeros, int *nb_spaces)
{
    calcul_nb_character(nb, nb_character_nb);
    *nb_zeros -= *nb_character_nb;
    if (*nb_zeros < 0) {
        *nb_zeros = 0;
    }
    *nb_spaces -= *nb_character_nb + *nb_zeros;
}

static int print_all(int nb, char *modifiers,
    int nb_min_char, int nb_precision)
{
    int nb_spaces = nb_min_char;
    int nb_zeros = nb_precision;
    int nb_character_nb = 0;
    int length = 0;

    set_numbers(&nb_character_nb, nb, &nb_zeros, &nb_spaces);
    if (nb < 0 || in_modifiers(0, '+', modifiers) == 1 ||
        in_modifiers(0, ' ', modifiers) == 1) {
        nb_spaces -= 1;
    }
    test_replace_zero(modifiers, &nb_zeros, &nb_spaces);
    if (in_modifiers(0, '-', modifiers) == 0) {
        length += print_spaces(nb_spaces);
    }
    length += my_isneg_print(nb, modifiers);
    length += print_zeros(nb_zeros) + print_nbr(nb);
    if (in_modifiers(0, '-', modifiers) == 1) {
        length += print_spaces(nb_spaces);
    }
    return length;
}

int my_put_nbr2(va_list list, char *modifiers)
{
    int nb = 0;
    int nb_min_char = -1;
    int nb_precision = -1;
    int length = 0;

    nb = initialisation(&nb_min_char, &nb_precision, modifiers, list);
    length += print_all(nb, modifiers, nb_min_char, nb_precision);
    return length;
}
