/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** specifier_s
*/

#include "my.h"
#include "my_printf.h"
#include <stdarg.h>

static int initialisation_char(int *nb_min_char, int *nb_precision,
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
    return va_arg(list, int);
}

void specifier_c(va_list list, int *counter, char *modifiers)
{
    char c = 0;
    int nb_min_char = -1;
    int nb_precision = -1;
    int length = 1;

    c = initialisation_char(&nb_min_char, &nb_precision, modifiers, list);
    if (in_modifiers(0, '-', modifiers) != 1) {
        for (int i = 0; i < (nb_min_char - 1); i++) {
            my_putchar(' ');
            length++;
        }
    }
    my_putchar(c);
    if (in_modifiers(0, '-', modifiers) == 1) {
        for (int i = 0; i < (nb_min_char - 1); i++)	{
            my_putchar(' ');
            length++;
        }
    }
    *counter += length;
}
