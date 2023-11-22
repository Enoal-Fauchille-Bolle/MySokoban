/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** specifier_s
*/
#include "my.h"
#include "my_printf.h"
#include <stdarg.h>

static void display_negation(double *f, int *counter)
{
    if (*f < 0.) {
        *counter += my_printf("-");
        *f *= -1.;
    }
}

static int print_zeros_before(double f)
{
    int i = 0;

    while ((int)(f * 10) == 0 && f != 0.0) {
        f = f * 10;
        my_putchar('0');
        i++;
    }
    return i;
}

static double initialisation(int *nb_min_char, int *nb_precision,
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
    return va_arg(list, double);
}

static void print_before_comma(double f, char *modifiers,
    int *counter, int nb_zeros)
{
    if (f >= 0. && (in_modifiers(0, '+', modifiers) ||
        in_modifiers(0, ' ', modifiers))) {
        if (in_modifiers(0, '+', modifiers))
            *counter += my_printf("+");
        else
            *counter += my_printf(" ");
    }
    display_negation(&f, counter);
    print_zeros(nb_zeros);
    *counter += my_printf("%d.", (int)f) - 1;
}

static void print_after_comma(double f, char *modifiers,
    int *nb_precision, int *dec_f)
{
    f -= (double)((int)f);
    *nb_precision -= print_zeros_before(f);
    if (number_in_modifiers(2, modifiers) == -1) {
        f *= my_compute_power_rec(10, *nb_precision);
    } else {
        f *= exponent(10, my_getnbr_modifiers(my_slice(modifiers,
            number_in_modifiers(2, modifiers), my_strlen(modifiers))));
    }
    *dec_f = (int)((f - (int)f) * 10.);
    if (*dec_f >= 5) {
        f += 1.;
    }
    *nb_precision -= my_printf("%d", (int)f);
    print_zeros(*nb_precision);
}

static int calcul_char_float(double f, int nb_precision, char *modifiers)
{
    int nb_char = 0;

    calcul_nb_character((int)f, &nb_char);
    nb_char++;
    nb_char += nb_precision;
    if (f < 0 || in_modifiers(0, '+', modifiers) == 1
        || in_modifiers(0, ' ', modifiers) == 1) {
        nb_char++;
    }
    return nb_char;
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

static void print_spaces_not_neg(char *modifiers, int nb_spaces)
{
    if (in_modifiers(0, '-', modifiers) != 1) {
        print_spaces(nb_spaces);
    }
}

static void print_nbr_float(double *f, char *modifiers,
    int *counter, int nb_zeros)
{
    print_before_comma(*f, modifiers, counter, nb_zeros);
    if (*f < 0) {
        *f = -(*f);
    }
}

void specifier_f(va_list list, int *counter, char *modifiers)
{
    double f = 0.0;
    int dec_f = 0;
    int nb_min_char = -1;
    int nb_precision = 6;
    int nb_char = 0;
    int nb_spaces = 0;
    int nb_zeros = 0;

    f = initialisation(&nb_min_char, &nb_precision, modifiers, list);
    nb_char = calcul_char_float(f, nb_precision, modifiers);
    nb_spaces = nb_min_char - nb_char;
    test_replace_zero(modifiers, &nb_zeros, &nb_spaces);
    print_spaces_not_neg(modifiers, nb_spaces);
    print_nbr_float(&f, modifiers, counter, nb_zeros);
    print_after_comma(f, modifiers, &nb_precision, &dec_f);
    if (in_modifiers(0, '-', modifiers) == 1) {
        print_spaces(nb_spaces);
    }
    *counter += nb_char;
}
