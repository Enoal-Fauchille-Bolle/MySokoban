/*
** EPITECH PROJECT, 2023
** the specifier X
** File description:
** specifier for hexadecimal in MAJ
*/
#include "my.h"
#include "my_printf.h"
#include <stdlib.h>

static int length_int(unsigned int nb, char *modifiers)
{
    int len = 1;

    while ((nb / my_compute_power_rec(10, len - 1)) >= 10) {
        len++;
    }
    if (in_modifiers(0, '#', modifiers) == 1
        && number_in_modifiers(2, modifiers) == -1) {
        len += 2;
    }
    return len;
}

static void int_to_str(unsigned int nb, char *str, int length)
{
    for (int j = length - 1; j >= 0; j--) {
        str[length - j - 1] = nb /
            my_compute_power_rec(10, j) + '0';
        nb -= nb / my_compute_power_rec(10, j)
            * my_compute_power_rec(10, j);
    }
}

static unsigned int initialisation(int *nb_min_char, int *nb_precision,
    char *modifiers, va_list list)
{
    int start_min = number_in_modifiers(1, modifiers);
    int start_prec = number_in_modifiers(2, modifiers);

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

static void set_numbers(int length, int *nb_zeros, int *nb_spaces)
{
    *nb_zeros -= length;
    if (*nb_zeros < 0) {
        *nb_zeros = 0;
    }
    *nb_spaces -= length + *nb_zeros;
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

static int test_modifiers(int length, int *nb_zeros,
    int *nb_spaces, char *modifiers)
{
    set_numbers(length, nb_zeros, nb_spaces);
    if (in_modifiers(0, '#', modifiers) == 1) {
        *nb_spaces -= 2;
    }
    test_replace_zero(modifiers, nb_zeros, nb_spaces);
    if (in_modifiers(0, '-', modifiers) == 0) {
        return print_spaces(*nb_spaces);
    }
    return 0;
}

static int print_all(char *modifiers, char *str,
    int nb_min_char, int nb_precision)
{
    int nb_spaces = nb_min_char;
    int nb_zeros = nb_precision;
    int length = my_strlen(str);
    int count = 0;

    count += test_modifiers(length, &nb_zeros, &nb_spaces, modifiers);
    if (in_modifiers(0, '#', modifiers) == 1) {
        my_putstr("0X");
        count += 2;
    }
    count += print_zeros(nb_zeros);
    my_putstr(str);
    count += my_strlen(str);
    if (in_modifiers(0, '-', modifiers) == 1) {
        count += print_spaces(nb_spaces);
    }
    return count;
}

static int test_modifiers_zero(int length, int *nb_zeros,
    int *nb_spaces, char *modifiers)
{
    set_numbers(length, nb_zeros, nb_spaces);
    if (in_modifiers(0, '#', modifiers) == 1 &&
        number_in_modifiers(2, modifiers) == -1) {
        *nb_spaces -= 2;
    }
    test_replace_zero(modifiers, nb_zeros, nb_spaces);
    if (in_modifiers(0, '-', modifiers) == 0) {
        return print_spaces(*nb_spaces);
    }
    return 0;
}

static int print_zero(char *modifiers, int nb_min_char, int nb_precision)
{
    int nb_spaces = nb_min_char;
    int nb_zeros = nb_precision;
    int length = 1;
    int count = 0;

    count += test_modifiers_zero(length, &nb_zeros, &nb_spaces, modifiers);
    if (in_modifiers(0, '#', modifiers) == 1 &&
        number_in_modifiers(2, modifiers) == -1) {
        my_putstr("0X");
        count += 2;
    }
    count += print_zeros(nb_zeros);
    my_putchar('0');
    count += 1;
    if (in_modifiers(0, '-', modifiers) == 1) {
        count += print_spaces(nb_spaces);
    }
    return count;
}

void specifier_x_maj(va_list list, int *counter, char *modifiers)
{
    unsigned int nb;
    char *str;
    int length = 0;
    int nb_min_char = -1;
    int nb_precision = -1;

    nb = initialisation(&nb_min_char, &nb_precision, modifiers, list);
    counter = counter;
    length = length_int(nb, modifiers);
    str = malloc(sizeof(char) * length + 1);
    int_to_str(nb, str, length);
    str = convert_base(str, "0123456789", "0123456789ABCDEF");
    if (nb == 0) {
        *counter += print_zero(modifiers, nb_min_char, nb_precision);
    } else {
        *counter += print_all(modifiers, str, nb_min_char, nb_precision);
    }
}
