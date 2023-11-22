/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** specifier_s
*/

#include "my.h"
#include "my_printf.h"
#include <stdarg.h>
#include <stdlib.h>

static int width_mode(char *modifiers)
{
    return number_in_modifiers(1, modifiers) != -1 ||
        in_modifiers(1, '*', modifiers);
}

static int negative_width(char *modifiers, int width)
{
    return in_modifiers(0, '-', modifiers) || width < 0;
}

static void display_spaces(char *modifiers, char *str, int *counter, int width)
{
    if (!in_modifiers(1, '*', modifiers))
        width = my_getnbr_modifiers(my_slice(modifiers,
            number_in_modifiers(1, modifiers), my_strlen(modifiers)));
    if (width < 0)
        width *= -1;
    for (int i = 0; i < width - my_strlen(str); i++) {
        my_putchar(' ');
        *counter += 1;
    }
}

void setup_str(char **str, va_list list, int *counter, char *modifiers)
{
    char *str_arg = va_arg(list, char *);
    int i = 0;
    int needed_length;
    char *temp;

    if (number_in_modifiers(2, modifiers) == -1) {
        *str = str_arg;
        *counter += my_strlen(str_arg);
    } else {
        needed_length = my_getnbr_modifiers(my_slice(modifiers,
            number_in_modifiers(2, modifiers),
            my_strlen(modifiers)));
        temp = malloc(sizeof(char) * needed_length);
        while (i < needed_length && str_arg[i] != '\0') {
            temp[i] = str_arg[i];
            *counter += 1;
            i++;
        }
        *str = temp;
    }
}

void specifier_s(va_list list, int *counter, char *modifiers)
{
    int width;
    char *str;

    if (in_modifiers(1, '*', modifiers))
        width = va_arg(list, int);
    setup_str(&str, list, counter, modifiers);
    if (width_mode(modifiers) != -1 &&
        !negative_width(modifiers, width)) {
        display_spaces(modifiers, str, counter, width);
    }
    my_putstr(str);
    if (width_mode(modifiers) != -1 &&
        negative_width(modifiers, width)) {
        display_spaces(modifiers, str, counter, width);
    }
}
